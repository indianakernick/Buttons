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
  using namespace ObjectType;

  auto view = registry.view<Collision, Activation, Button>();
  for (EntityID entity : view) {
    const auto &collisionPairs = view.get<Collision>(entity).collisionPairs;
    view.get<Activation>(entity).active = collisionPairs.hasPair<ButtonBase, ButtonTop>();
  }
}
