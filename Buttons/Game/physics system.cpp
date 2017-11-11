//
//  physics system.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "physics system.hpp"

#include <algorithm>
#include "physics constants.hpp"

void PhysicsSystem::init(Registry &newRegistry) {
  world.emplace(GRAVITY);
  contactListener.emplace();
  world->SetContactListener(&(*contactListener));
  
  registry = &newRegistry;
}

void PhysicsSystem::quit() {
  registry = nullptr;
  
  world->SetContactListener(nullptr);
  contactListener = std::experimental::nullopt;
  world = std::experimental::nullopt;
}

b2World *PhysicsSystem::getWorld() {
  return &(*world);
}

void PhysicsSystem::update(const float delta) {
  world->Step(delta, VELOCITY_ITER, POSITION_ITER);
}

void PhysicsSystem::beginContact(
  const EntityID entityA,
  const EntityID entityB,
  const CollisionPair pair
) {
  if (registry->has<Collision>(entityA)) {
    registry->get<Collision>(entityA).collisionPairs.addPair(pair);
  }
  if (registry->has<Collision>(entityB)) {
    registry->get<Collision>(entityB).collisionPairs.addPair(pair);
  }
}

void PhysicsSystem::endContact(
  const EntityID entityA,
  const EntityID entityB,
  const CollisionPair pair
) {
  if (registry->has<Collision>(entityA)) {
    registry->get<Collision>(entityA).collisionPairs.remPair(pair);
  }
  if (registry->has<Collision>(entityB)) {
    registry->get<Collision>(entityB).collisionPairs.remPair(pair);
  }
}
