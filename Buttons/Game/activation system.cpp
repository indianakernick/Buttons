//
//  activation system.cpp
//  Buttons
//
//  Created by Indi Kernick on 12/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "activation system.hpp"

#include "activation component.hpp"

void activationSystem(Registry &registry, const float delta) {
  auto view = registry.view<Activation>();
  for (const EntityID entity : view) {
    Activation &comp = view.get(entity);
    if (comp.state == Activation::State::ACTIVATING) {
      comp.activity = std::min(comp.activity + comp.speed * delta, 1.0f);
      if (comp.activity >= 1.0f) {
        comp.state = Activation::State::ACTIVE;
      }
    } else if (comp.state == Activation::State::DEACTIVATING) {
      comp.activity = std::max(comp.activity - comp.speed * delta, 0.0f);
      if (comp.activity <= 0.0f) {
        comp.state = Activation::State::INACTIVE;
      }
    }
  }
}
