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

void powerInputActivationSystem(entt::Registry<EntityID> &registry) {
  auto view = registry.view<PowerInput, Activation>();
  for (EntityID id : view) {
    view.get<Activation>(id).active = view.get<PowerInput>(id).on;
  }
}
