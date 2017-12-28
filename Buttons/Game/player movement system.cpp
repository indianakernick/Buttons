//
//  player movement system.cpp
//  Buttons
//
//  Created by Indi Kernick on 11/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "player movement system.hpp"

#include "object types.hpp"
#include "physics component.hpp"
#include "collision component.hpp"
#include "player jump component.hpp"
#include "player input component.hpp"
#include <Simpleton/Box2D/limit velocity.hpp>

namespace {
  constexpr float MOVE_FORCE = 100.0f;
  constexpr float AIR_MOVE_FORCE = 50.0f;
  constexpr float JUMP_FORCE = 160.0f;
  constexpr float MAX_JUMP_DUR = 0.2f;
  constexpr float MAX_MOVE_VEL = 4.0f;
  
  bool isOnGround(const Collision &collision) {
    const CollisionPairs &pairs = collision.collisionPairs;
    return pairs.hasPair<B2::ObjT::PlayerFoot, B2::ObjT::Ground>();
  }
  
  void move(b2Body *const body, const float dir, const bool onGround) {
    const float forceMag = onGround ? MOVE_FORCE : AIR_MOVE_FORCE;
    body->ApplyForceToCenter({forceMag * dir, 0.0f}, true);
  }
}

void playerMovementSystem(ECS::Registry &registry, const float delta) {
  auto view = registry.view<PlayerInput, PlayerJump, Collision, PhysicsBody>();
  for (const ECS::EntityID entity : view) {
    const PlayerInput input = view.get<PlayerInput>(entity);
    b2Body *const body = view.get<PhysicsBody>(entity).body;
    const bool onGround = isOnGround(view.get<Collision>(entity));
    
    if (input.left && !input.right) {
      move(body, -1.0f, onGround);
    } else if (input.right && !input.left) {
      move(body, 1.0f, onGround);
    }
    
    //@TODO this should happen after the physics world is stepped, not before
    body->SetLinearVelocity(B2::limitVelX(body->GetLinearVelocity(), {0.0f, 0.0f}, MAX_MOVE_VEL));
    
    PlayerJump &jump = view.get<PlayerJump>(entity);
    if (input.jump) {
      if (onGround && jump.timeTillEnd == 0.0f) {
        jump.timeTillEnd = MAX_JUMP_DUR;
      }
      if (jump.timeTillEnd > 0.0f) {
        body->ApplyForceToCenter({0.0f, JUMP_FORCE}, true);
        jump.timeTillEnd = std::max(jump.timeTillEnd - delta, 0.0f);
      }
    } else {
      jump.timeTillEnd = 0.0f;
    }
  }
}
