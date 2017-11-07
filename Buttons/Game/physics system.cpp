//
//  physics system.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "physics system.hpp"

#include "physics constants.hpp"

void PhysicsSystem::init() {
  world.emplace(GRAVITY);
  contactListener.emplace();
  world->SetContactListener(&(*contactListener));
}

void PhysicsSystem::quit() {
  world->SetContactListener(nullptr);
  contactListener = std::experimental::nullopt;
  world = std::experimental::nullopt;
}

void PhysicsSystem::update(const float delta) {
  world->Step(delta, VELOCITY_ITER, POSITION_ITER);
}

void PhysicsSystem::iterate(entt::Registry<EntityID> &registry) {
  
}
