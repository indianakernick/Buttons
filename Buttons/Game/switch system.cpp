//
//  switch system.cpp
//  Buttons
//
//  Created by Indi Kernick on 12/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "switch system.hpp"

#include "switch component.hpp"
#include "collision component.hpp"
#include "collision categories.hpp"
#include "activation component.hpp"
#include "player input component.hpp"

namespace {
  using State = Activation::State;
  
  void toggle(State &state) {
    if (state == State::ACTIVE) {
      state = State::DEACTIVATING;
    } else if (state == State::INACTIVE) {
      state = State::ACTIVATING;
    }
  }
}

void switchSystem(Registry &registry) {
  auto view = registry.view<Switch, Collision, Activation>();
  for (const EntityID entity : view) {
    const CollisionPairs &pairs = view.get<Collision>(entity).collisionPairs;
    const EntityID player = pairs.getHalfPair<ObjectType::PlayerBody>();
    if (player != NULL_ENTITY && registry.get<PlayerInput>(player).action) {
      toggle(view.get<Activation>(entity).state);
    }
  }
}
