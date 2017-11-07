//
//  physics system.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "physics system.hpp"

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

void PhysicsSystem::update(const float delta) {
  world->Step(delta, VELOCITY_ITER, POSITION_ITER);
}

//This system will fail when more than one object of the same type collides with
//another object. I'm pretty sure that won't happen during the game. The button
//top can only every collide with one other button base. This system will fail
//if a button base collides with more than one button top but this won't happen.

void PhysicsSystem::beginContact(
  const EntityID entityA,
  const EntityID entityB,
  const uint16_t catA,
  const uint16_t catB
) {
  if (registry->has<Collision>(entityA)) {
    registry->get<Collision>(entityA).collidingCategory |= catB;
  }
  if (registry->has<Collision>(entityB)) {
    registry->get<Collision>(entityB).collidingCategory |= catA;
  }
}

void PhysicsSystem::endContact(
  const EntityID entityA,
  const EntityID entityB,
  const uint16_t catA,
  const uint16_t catB
) {
  if (registry->has<Collision>(entityA)) {
    registry->get<Collision>(entityA).collidingCategory &= ~catB;
  }
  if (registry->has<Collision>(entityB)) {
    registry->get<Collision>(entityB).collidingCategory &= ~catA;
  }
}
