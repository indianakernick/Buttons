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
  auto singleInput = registry.view<Activation, PowerInput>();
  for (const EntityID entity : singleInput) {
    Activation::State &state = singleInput.get<Activation>(entity).state;
    if (singleInput.get<PowerInput>(entity).on) {
      activate(state);
    } else {
      deactivate(state);
    }
  }
}
