//
//  activate power output system.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "activate power output system.hpp"

#include "power component.hpp"
#include "activation component.hpp"

void activatePowerOutputSystem(ECS::Registry &registry) {
  auto view = registry.view<PowerOutput, Activation>();
  for (const ECS::EntityID entity : view) {
    view.get<PowerOutput>(entity).on = isActive(view.get<Activation>(entity).state);
  }
}
