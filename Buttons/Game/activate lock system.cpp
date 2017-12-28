//
//  activate lock system.cpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "activate lock system.hpp"

#include "lock component.hpp"
#include "collision component.hpp"
#include "activation component.hpp"
#include "player keys component.hpp"

void activateLockSystem(ECS::Registry &registry) {
  auto view = registry.view<Lock, Collision, Activation>();
  const auto playerKeys = registry.view<PlayerKeys>();
  
  for (const ECS::EntityID entity : view) {
    Activation::State &activeState = view.get<Activation>(entity).state;
    if (isActive(activeState)) {
      continue;
    }
    
    const CollisionPairs &pairs = view.get<Collision>(entity).collisionPairs;
    const ECS::EntityID player = pairs.getHalfPair<B2::ObjT::PlayerBody>();
    if (player != ECS::NULL_ENTITY) {
      if (playerKeys.get(player).keys[view.get<Lock>(entity).index]) {
        activate(activeState);
      }
    }
  }
}
