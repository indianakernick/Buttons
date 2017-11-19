//
//  button system.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "button system.hpp"

#include "button component.hpp"
#include "collision component.hpp"
#include "collision categories.hpp"
#include "activation component.hpp"

void buttonSystem(Registry &registry) {
  auto view = registry.view<Collision, Activation, Button>();
  for (const EntityID entity : view) {
    const auto &collisions = view.get<Collision>(entity).collisionPairs;
    if (collisions.hasAny()) {
      activate(view.get<Activation>(entity).state);
    } else {
      deactivate(view.get<Activation>(entity).state);
    }
  }
}
