//
//  inverter system.cpp
//  Buttons
//
//  Created by Indi Kernick on 21/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "inverter system.hpp"

#include "power component.hpp"
#include "inverter component.hpp"

void inverterSystem(Registry &registry) {
  auto view = registry.view<PowerInput, PowerOutput, Inverter>();
  for (const EntityID entity : view) {
    view.get<PowerOutput>(entity).on = !view.get<PowerInput>(entity).on;
  }
}
