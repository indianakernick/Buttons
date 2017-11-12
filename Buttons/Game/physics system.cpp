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
#include <Simpleton/Utils/member function.hpp>

void PhysicsSystem::init(Registry &newRegistry, NVGcontext *const ctx) {
  world.emplace(GRAVITY);
  
  contactListener.emplace();
  world->SetContactListener(&(*contactListener));
  contactListener->setBeginListener(Utils::memFun(this, &PhysicsSystem::beginContact));
  contactListener->setEndListener(Utils::memFun(this, &PhysicsSystem::endContact));
  
  debugDraw.emplace();
  world->SetDebugDraw(&(*debugDraw));
  debugDraw->setContext(ctx);
  
  registry = &newRegistry;
}

void PhysicsSystem::quit() {
  registry = nullptr;
  
  debugDraw->setContext(nullptr);
  world->SetDebugDraw(nullptr);
  debugDraw = std::experimental::nullopt;
  
  contactListener->setEndListener(nullptr);
  contactListener->setBeginListener(nullptr);
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

void PhysicsSystem::render() {
  world->DrawDebugData();
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
