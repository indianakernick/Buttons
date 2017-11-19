//
//  power input activation system.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "power input activation system.hpp"

#include "power component.hpp"
#include "activation component.hpp"

void powerInputActivationSystem(Registry &registry) {
  auto view = registry.view<Activation, PowerInput>();
  for (const EntityID entity : view) {
    if (view.get<PowerInput>(entity).on) {
      activate(view.get<Activation>(entity).state);
    } else {
      deactivate(view.get<Activation>(entity).state);
    }
  }
}
