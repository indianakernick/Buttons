//
//  power system.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "power system.hpp"

#include "power component.hpp"

void powerSystem(Registry &registry) {
  const auto powerOutput = registry.view<PowerOutput>();
  auto powerInput = registry.view<PowerInput>();
  for (EntityID entity : powerInput) {
    PowerInput &input = powerInput.get(entity);
    if (input.in != NULL_ENTITY) {
      input.on = powerOutput.get(input.in).on;
    }
  }
}
