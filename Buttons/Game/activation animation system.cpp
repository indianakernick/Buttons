//
//  activation animation system.cpp
//  Buttons
//
//  Created by Indi Kernick on 21/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "activation animation system.hpp"

#include "animation component.hpp"
#include "activation component.hpp"

void activationAnimationSystem(Registry &registry) {
  auto view = registry.view<Animation, Activation>();
  for (const EntityID entity : view) {
    Animation &anim = view.get<Animation>(entity);
    if (anim.speed == 0.0f) {
      anim.progress = view.get<Activation>(entity).activity;
    }
  }
}
