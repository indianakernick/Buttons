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
  for (EntityID entity : powerOutput) {
    const PowerOutput &outputComp = powerOutput.get(entity);
    //powerInput.get(outputComp.out).on = outputComp.on;
  }
}
