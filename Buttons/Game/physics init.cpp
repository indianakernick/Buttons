//
//  physics init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "physics init.hpp"

#include "object types.hpp"
#include "transform init.hpp"
#include "collision categories.hpp"
#include <Simpleton/Box2D/parse json.hpp>
#include <Simpleton/ECS/entity id map.hpp>

PhysicsBodyInit::PhysicsBodyInit(b2World *const world)
  : world(world) {
  assert(world);
}

void PhysicsBodyInit::init(
  PhysicsBody &comp,
  const json &node,
  const ECS::EntityIDmap &,
  const ECS::EntityID entity
) {
  Transform transform;
  TransformInit transformInit;
  transformInit.init(transform, node);
  comp.body = B2::loadBody(
    node.at("body"),
    *world,
    transform.pos,
    transform.scale,
    transform.rotation
  );
  B2::setEntity(comp.body, entity);
  comp.scale = transform.scale;
}

PhysicsJointInit::PhysicsJointInit(b2World *const world, ECS::Registry *const registry)
  : world(world), registry(registry) {
  assert(world);
  assert(registry);
}

namespace {
  b2Body *getBody(const json &node, const ECS::EntityIDmap &idMap, ECS::Registry *registry) {
    const ECS::ClientEntityID bodyClientID = node.get<ECS::ClientEntityID>();
    const ECS::EntityID bodyEntityID = idMap.getEntityFromID(bodyClientID);
    return registry->get<PhysicsBody>(bodyEntityID).body;
  }
}

void PhysicsJointInit::init(
  PhysicsJoint &comp,
  const json &node,
  const ECS::EntityIDmap &idMap,
  const ECS::EntityID entity
) {
  b2JointDef *const def = B2::loadJoint(node.at("joint"));
  B2::setEntity(def, entity);
  
  def->bodyA = getBody(node.at("body A"), idMap, registry);
  def->bodyB = getBody(node.at("body B"), idMap, registry);
  
  comp.joint = world->CreateJoint(def);
}

void PhysicsRayCastInit::init(PhysicsRayCast &comp, const json &node) {
  comp.start = node.at("start").get<b2Vec2>();
  comp.end = node.at("end").get<b2Vec2>();
}
