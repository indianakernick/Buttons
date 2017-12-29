//
//  physics file.cpp
//  Buttons
//
//  Created by Indi Kernick on 1/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "physics file.hpp"

#include <fstream>
#include "object types.hpp"
#include <Simpleton/Box2D/glm.hpp>
#include <Simpleton/SDL/paths.hpp>
#include <Simpleton/Box2D/json.hpp>
#include "collision categories.hpp"

namespace {
  b2BodyType readBodyType(const std::string &typeName) {
           if (typeName == "static") {
      return b2_staticBody;
    } else if (typeName == "kinematic") {
      return b2_kinematicBody;
    } else if (typeName == "dynamic") {
      return b2_dynamicBody;
    } else {
      throw std::runtime_error("Invalid body type");
    }
  }
  
  b2BodyDef readBodyDef(const json &bodyNode) {
    b2BodyDef bodyDef;
    
    bodyDef.type = readBodyType(bodyNode.at("type").get<std::string>());
    
    Data::getOptional(bodyDef.linearVelocity, bodyNode, "linear velocity");
    Data::getOptional(bodyDef.angularVelocity, bodyNode, "angular velocity");
    Data::getOptional(bodyDef.linearDamping, bodyNode, "linear damping");
    Data::getOptional(bodyDef.angularDamping, bodyNode, "angular damping");
    Data::getOptional(bodyDef.allowSleep, bodyNode, "allow sleep");
    Data::getOptional(bodyDef.awake, bodyNode, "awake");
    Data::getOptional(bodyDef.fixedRotation, bodyNode, "fixed rotation");
    Data::getOptional(bodyDef.bullet, bodyNode, "bullet");
    Data::getOptional(bodyDef.gravityScale, bodyNode, "gravity scale");
    
    return bodyDef;
  }
  
  std::vector<b2Vec2> readVecs(const json &vecsNode, const b2Vec2 scale) {
    auto vecs = vecsNode.get<std::vector<b2Vec2>>();
    for (auto &vec : vecs) {
      vec.x *= scale.x;
      vec.y *= scale.y;
    }
    return vecs;
  }
  
  b2Vec2 mul(const b2Vec2 vec, const b2Vec2 scale) {
    return {
      vec.x * scale.x,
      vec.y * scale.y
    };
  }
  
  float32 mul(const float32 scalar, const b2Vec2 scale) {
    return scalar * (scale.x + scale.y) * 0.5f;
  }
  
  #define OPTIONAL_VEC(OBJ, NODE, MEMBER, HAS_MEMBER, NAME)                     \
    if (const auto vert = NODE.find(NAME); vert != NODE.cend()) {               \
      OBJ.m_##MEMBER = mul(vert->get<b2Vec2>(), scale);                         \
      OBJ.m_##HAS_MEMBER = true;                                                \
    } do{}while(0)
  
  b2CircleShape *readCircle(const json &circleNode, const b2Vec2 scale) {
    static b2CircleShape circle;
    circle = {};
    
    circle.m_p = mul(circleNode.at("pos").get<b2Vec2>(), scale);
    circle.m_radius = mul(circleNode.at("radius").get<float32>(), scale);
    
    return &circle;
  }
  
  b2EdgeShape *readEdge(const json &edgeNode, const b2Vec2 scale) {
    static b2EdgeShape edge;
    edge = {};
    
    OPTIONAL_VEC(edge, edgeNode, vertex0, hasVertex0, "vert 0");
    edge.m_vertex1 = mul(edgeNode.at("vert 1").get<b2Vec2>(), scale);
    edge.m_vertex2 = mul(edgeNode.at("vert 2").get<b2Vec2>(), scale);
    OPTIONAL_VEC(edge, edgeNode, vertex3, hasVertex3, "vert 3");
    
    return &edge;
  }
  
  b2PolygonShape *readPolygon(const json &polygonNode, const b2Vec2 scale) {
    static b2PolygonShape polygon;
    polygon = {};
    
    if (const auto vertsNode = polygonNode.find("verts"); vertsNode != polygonNode.cend()) {
      const std::vector<b2Vec2> verts = readVecs(*vertsNode, scale);
      if (verts.size() > b2_maxPolygonVertices) {
        throw std::runtime_error("Too many verties for polygon");
      }
      polygon.Set(verts.data(), static_cast<int32>(verts.size()));
    } else {
      const b2Vec2 halfSize = mul(polygonNode.at("half size").get<b2Vec2>(), scale);
      polygon.SetAsBox(std::abs(halfSize.x), std::abs(halfSize.y));
    }
    
    return &polygon;
  }
  
  b2ChainShape *readChain(const json &chainNode, const b2Vec2 scale) {
    static b2ChainShape chain;
    chain = {};
    
    bool isLoop = false;
    Data::getOptional(isLoop, chainNode, "is loop");
    const std::vector<b2Vec2> verts = readVecs(chainNode.at("verts"), scale);
    
    if (isLoop) {
      chain.CreateLoop(verts.data(), static_cast<int32>(verts.size()));
    } else {
      chain.CreateChain(verts.data(), static_cast<int32>(verts.size()));
      
      OPTIONAL_VEC(chain, chainNode, prevVertex, hasPrevVertex, "prev vert");
      OPTIONAL_VEC(chain, chainNode, nextVertex, hasNextVertex, "next vert");
    }
    
    return &chain;
  }
  
  #undef OPTIONAL_VEC
  
  b2Shape *readShape(const json &shapeNode, const b2Vec2 scale) {
    const std::string typeName = shapeNode.at("type").get<std::string>();
    
           if (typeName == "circle") {
      return readCircle(shapeNode, scale);
    } else if (typeName == "edge") {
      return readEdge(shapeNode, scale);
    } else if (typeName == "polygon") {
      return readPolygon(shapeNode, scale);
    } else if (typeName == "chain") {
      return readChain(shapeNode, scale);
    } else {
      throw std::runtime_error("Invalid shape type");
    }
  }
  
  uint16_t getCategoryBits(const json &node) {
    if (node.is_array()) {
      uint16_t bits = 0;
      for (auto &c : node) {
        bits |= B2::getCategoryBit(c.get<std::string>());
      }
      return bits;
    } else {
      return B2::getCategoryBit(node.get<std::string>());
    }
  }
  
  b2Filter readFilter(const json &filterNode) {
    b2Filter filter;
    if (const auto catNode = filterNode.find("category"); catNode != filterNode.cend()) {
      filter.categoryBits = getCategoryBits(*catNode);
    }
    if (const auto maskNode = filterNode.find("collide with"); maskNode != filterNode.cend()) {
      filter.maskBits = getCategoryBits(*maskNode);
    } else if (const auto maskNode = filterNode.find("no collide with"); maskNode != filterNode.cend()) {
      filter.maskBits = ~getCategoryBits(*maskNode);
    }
    Data::getOptional(filter.groupIndex, filterNode, "group");
    return filter;
  }
  
  void readFixture(b2Body *const body, const json &fixtureNode, const b2Vec2 scale) {
    b2FixtureDef fixtureDef;
    fixtureDef.shape = readShape(fixtureNode.at("shape"), scale);
    
    Data::getOptional(fixtureDef.friction, fixtureNode, "friction");
    Data::getOptional(fixtureDef.restitution, fixtureNode, "restitution");
    Data::getOptional(fixtureDef.density, fixtureNode, "density");
    Data::getOptional(fixtureDef.isSensor, fixtureNode, "is sensor");
    
    if (const auto userDataNode = fixtureNode.find("user data"); userDataNode != fixtureNode.cend()) {
      fixtureDef.userData = B2::getObjectTypeUserData(userDataNode->get<std::string>());
    }
    if (const auto filterNode = fixtureNode.find("filter"); filterNode != fixtureNode.cend()) {
      fixtureDef.filter = readFilter(*filterNode);
    }
    
    body->CreateFixture(&fixtureDef);
  }
  
  void readFixtures(b2Body *const body, const json &fixturesNode, const b2Vec2 scale) {
    for (auto &f : fixturesNode) {
      readFixture(body, f, scale);
    }
  }
}

b2Body *loadBody(const json &node, b2World &world, const Transform transform) {
  const b2BodyDef bodyDef = readBodyDef(node.at("body"));
  b2Body *const body = world.CreateBody(&bodyDef);
  body->SetTransform(B2::cast(transform.pos), transform.rotation);
  readFixtures(body, node.at("fixtures"), B2::cast(transform.scale));
  return body;
}

b2Body *loadBody(
  const std::string &fileName,
  b2World &world,
  const Transform transform
) {
  std::ifstream file(SDL::getResDir() + fileName);
  json rootNode;
  file >> rootNode;
  return loadBody(rootNode, world, transform);
}

namespace {
  #define READ_ANCHOR                                                           \
  Data::getOptional(def->localAnchorA, node, "local anchor A");                 \
  Data::getOptional(def->localAnchorB, node, "local anchor B");
  
  #define READ_FREQ_DAMP                                                        \
  Data::getOptional(def->frequencyHz, node, "frequency");                       \
  Data::getOptional(def->dampingRatio, node, "damping ratio");

  void readRevolute(b2RevoluteJointDef *def, const json &node) {
    READ_ANCHOR
    Data::getOptional(def->referenceAngle, node, "reference angle");
    Data::getOptional(def->lowerAngle, node, "lower angle");
    Data::getOptional(def->upperAngle, node, "upper angle");
    Data::getOptional(def->maxMotorTorque, node, "max motor torque");
    Data::getOptional(def->motorSpeed, node, "motor speed");
    Data::getOptional(def->enableLimit, node, "enable limit");
    Data::getOptional(def->enableMotor, node, "enable motor");
  }
  
  void readPrismatic(b2PrismaticJointDef *def, const json &node) {
    READ_ANCHOR
    Data::getOptional(def->localAxisA, node, "local axis A");
    Data::getOptional(def->referenceAngle, node, "reference angle");
    Data::getOptional(def->enableLimit, node, "enable limit");
    Data::getOptional(def->lowerTranslation, node, "lower translation");
    Data::getOptional(def->upperTranslation, node, "upper translation");
    Data::getOptional(def->enableMotor, node, "enable motor");
    Data::getOptional(def->maxMotorForce, node, "max motor force");
    Data::getOptional(def->motorSpeed, node, "motor speed");
  }
  
  void readDistance(b2DistanceJointDef *def, const json &node) {
    READ_ANCHOR
    READ_FREQ_DAMP
    Data::getOptional(def->length, node, "length");
  }
  
  void readPulley(b2PulleyJointDef *def, const json &node) {
    READ_ANCHOR
    Data::getOptional(def->groundAnchorA, node, "ground anchor A");
    Data::getOptional(def->groundAnchorB, node, "ground anchor B");
    Data::getOptional(def->lengthA, node, "length A");
    Data::getOptional(def->lengthB, node, "length B");
    Data::getOptional(def->ratio, node, "ratio");
  }
  
  void readMouse(b2MouseJointDef *def, const json &node) {
    READ_FREQ_DAMP
    Data::getOptional(def->target, node, "target");
    Data::getOptional(def->maxForce, node, "max force");
  }
  
  void readWheel(b2WheelJointDef *def, const json &node) {
    READ_ANCHOR
    READ_FREQ_DAMP
    Data::getOptional(def->localAxisA, node, "local axis A");
    Data::getOptional(def->enableMotor, node, "enable motor");
    Data::getOptional(def->maxMotorTorque, node, "max motor torque");
    Data::getOptional(def->motorSpeed, node, "motor speed");
  }
  
  void readWeld(b2WeldJointDef *def, const json &node) {
    READ_ANCHOR
    READ_FREQ_DAMP
    Data::getOptional(def->referenceAngle, node, "reference angle");
  }
  
  void readFriction(b2FrictionJointDef *def, const json &node) {
    READ_ANCHOR
    Data::getOptional(def->maxForce, node, "max force");
    Data::getOptional(def->maxTorque, node, "max torque");
  }
  
  void readRope(b2RopeJointDef *def, const json &node) {
    READ_ANCHOR
    Data::getOptional(def->maxLength, node, "max length");
  }
  
  void readMotor(b2MotorJointDef *def, const json &node) {
    Data::getOptional(def->linearOffset, node, "linear offset");
    Data::getOptional(def->angularOffset, node, "angular offset");
    Data::getOptional(def->maxForce, node, "max force");
    Data::getOptional(def->maxTorque, node, "max torque");
    Data::getOptional(def->correctionFactor, node, "correction factor");
  }
  
  #undef READ_FREQ_DAMP
  #undef READ_ANCHOR
  
  #define JOINTS                                                                \
    JOINT(Revolute, revolute)                                                   \
    JOINT(Prismatic, prismatic)                                                 \
    JOINT(Distance, distance)                                                   \
    JOINT(Pulley, pulley)                                                       \
    JOINT(Mouse, mouse)                                                         \
    JOINT(Wheel, wheel)                                                         \
    JOINT(Weld, weld)                                                           \
    JOINT(Friction, friction)                                                   \
    JOINT(Rope, rope)                                                           \
    JOINT(Motor, motor)

  b2JointDef *loadJoint(const json &node) {
    #define JOINT(CLASS, NAME)                                                  \
      if (type == #NAME) {                                                      \
        static b2##CLASS##JointDef def;                                         \
        def = {};                                                               \
        read##CLASS(&def, node);                                                \
        jointDef = &def;                                                        \
      } else
    
    const std::string type = node.at("type").get<std::string>();
    b2JointDef *jointDef;
    
    JOINTS
    /* else */ {
      throw std::runtime_error("Invalid joint type");
    }
    
    #undef JOINT
    
    Data::getOptional(jointDef->collideConnected, node, "collide connected");
    
    return jointDef;
  }
}

void readJoint(b2JointDef *def, const json &node) {
  #define JOINT(CLASS, NAME)                                                    \
    case b2JointType::e_##NAME##Joint:                                          \
      read##CLASS(static_cast<b2##CLASS##JointDef *>(def), node);               \
      break;

  Data::getOptional(def->collideConnected, node, "collide connected");

  switch (def->type) {
    JOINTS
    
    default:
      throw std::runtime_error("Invalid joint type");
  }
  
  #undef JOINT
  #undef JOINTS
}

b2JointDef *loadJoint(const std::string &fileName) {
  std::ifstream file(SDL::getResDir() + fileName);
  json rootNode;
  file >> rootNode;
  return loadJoint(rootNode);
}
