//
//  physics init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "physics init.hpp"

#include "yaml helper.hpp"
#include "physics file.hpp"
#include "entity id map.hpp"
#include <glm/trigonometric.hpp>
#include "physics body entity id.hpp"
#include "../Libraries/Box2D/Dynamics/b2World.h"

PhysicsBodyInit::PhysicsBodyInit(b2World *const world)
  : world(world) {
  assert(world);
}

void PhysicsBodyInit::init(
  PhysicsBody &comp,
  const YAML::Node &node,
  const EntityIDmap &idMap,
  const EntityID entity
) {
  /*Transform transform;
  getOptional(transform.pos, node, "pos");
  getOptional(transform.scale, node, "scale");
  getOptional(transform.rotation, node, "rotation");
  transform.rotation = glm::radians(transform.rotation);
  comp.body = loadBody(getChild(node, "body").Scalar(), *world, transform);
  comp.body->SetUserData(getUserData(entity));
  scale = transform.scale;*/
}
