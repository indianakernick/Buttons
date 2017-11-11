//
//  player movement system.cpp
//  Buttons
//
//  Created by Indi Kernick on 11/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "player movement system.hpp"

#include "limit velocity.hpp"
#include "physics component.hpp"
#include "collision component.hpp"
#include "player jump component.hpp"
#include "player input component.hpp"

namespace {
  constexpr float MOVE_FORCE = 100.0f;
}

void playerMovementSystem(Registry &registry, const float delta) {
  auto view = registry.view<PlayerInput, PlayerJump, Collision, PhysicsBody>();
  for (EntityID entity : view) {
    const PlayerInput input = view.get<PlayerInput>(entity);
    b2Body *const body = view.get<PhysicsBody>(entity).body;
    if (input.left) {
      body->ApplyForceToCenter({-MOVE_FORCE, 0.0f}, true);
    } else if (input.right) {
      body->ApplyForceToCenter({MOVE_FORCE, 0.0f}, true);
    }
  }
}
