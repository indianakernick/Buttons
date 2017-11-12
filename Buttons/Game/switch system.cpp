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

void switchSystem(Registry &registry) {
  auto view = registry.view<Switch, Collision, Activation>();
  for (EntityID entity : view) {
    const EntityID player = view.get<Switch>(entity).player;
    const bool action = registry.get<const PlayerInput>(player).action;
    const CollisionPairs &pairs = view.get<Collision>(entity).collisionPairs;
    if (pairs.hasHalfPair<ObjectType::PlayerBody>() && action) {
      Activation &active = view.get<Activation>(entity);
      if (active.state == Activation::State::ACTIVE) {
        active.state = Activation::State::DEACTIVATING;
      } else if (active.state == Activation::State::INACTIVE) {
        active.state = Activation::State::ACTIVATING;
      }
    }
  }
}
