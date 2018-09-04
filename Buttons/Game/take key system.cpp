//
//  take key system.cpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "take key system.hpp"

#include "key component.hpp"
#include "collision component.hpp"
#include "activation component.hpp"
#include "player keys component.hpp"

void takeKeySystem(ECS::Registry &registry) {
  auto view = registry.view<Key, Collision, Activation>();
  auto playerKeys = registry.view<PlayerKeys>();
  
  for (const ECS::EntityID entity : view) {
    Activation::State &activeState = view.get<Activation>(entity).state;
    if (isInactive(activeState)) {
      continue;
    }
    
    const B2::CollisionPairs &pairs = view.get<Collision>(entity).collisionPairs;
    const ECS::EntityID player = pairs.getHalfPair<B2::ObjT::PlayerBody>();
    if (player != entt::null) {
      playerKeys.get(player).keys[view.get<Key>(entity).index] = true;
      deactivate(activeState);
    }
  }
}
