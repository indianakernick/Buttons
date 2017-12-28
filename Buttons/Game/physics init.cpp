//
//  physics init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "physics init.hpp"

#include "physics file.hpp"
#include "entity id map.hpp"
#include "transform init.hpp"
#include <glm/trigonometric.hpp>
#include <Box2D/Dynamics/b2World.h>
#include <Simpleton/Box2D/entity id.hpp>

PhysicsBodyInit::PhysicsBodyInit(b2World *const world)
  : world(world) {
  assert(world);
}

void PhysicsBodyInit::init(
  PhysicsBody &comp,
  const json &node,
  const EntityIDmap &,
  const ECS::EntityID entity
) {
  Transform transform;
  TransformInit transformInit;
  transformInit.init(transform, node);
  comp.body = loadBody(node.at("body"), *world, transform);
  comp.body->SetUserData(B2::getUserData(entity));
  comp.scale = transform.scale;
}

PhysicsJointInit::PhysicsJointInit(b2World *const world, ECS::Registry *const registry)
  : world(world), registry(registry) {
  assert(world);
  assert(registry);
}

namespace {
  b2Body *getBody(const json &node, const EntityIDmap &idMap, ECS::Registry *registry) {
    const ClientEntityID bodyClientID = node.get<ClientEntityID>();
    const ECS::EntityID bodyEntityID = idMap.getEntityFromID(bodyClientID);
    return registry->get<PhysicsBody>(bodyEntityID).body;
  }
}

void PhysicsJointInit::init(
  PhysicsJoint &comp,
  const json &node,
  const EntityIDmap &idMap,
  const ECS::EntityID entity
) {
  //read the joint file
  b2JointDef *const def = loadJoint(node.at("joint").get<std::string>());
  //read the level file
  readJoint(def, node);
  
  def->bodyA = getBody(node.at("body A"), idMap, registry);
  def->bodyB = getBody(node.at("body B"), idMap, registry);
  def->userData = B2::getUserData(entity);
  
  comp.joint = world->CreateJoint(def);
}

void PhysicsRayCastInit::init(PhysicsRayCast &comp, const json &node) {
  comp.start = node.at("start").get<b2Vec2>();
  comp.end = node.at("end").get<b2Vec2>();
}
