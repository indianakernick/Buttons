//
//  animation system.cpp
//  Buttons
//
//  Created by Indi Kernick on 12/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "animation system.hpp"

#include "animation component.hpp"
#include <Simpleton/Time/progress speed anim.hpp>

void animationSystem(Registry &registry, const float delta) {
  auto view = registry.view<Animation>();
  for (EntityID entity : view) {
    Animation &comp = view.get(entity);
    Time::ProgSpeedAnim<float> anim(comp.progress, comp.speed);
    anim.advance(delta);
    if (comp.edgeMode == Animation::EdgeMode::REPEAT) {
      anim.repeatPastEdge();
    } else if (comp.edgeMode == Animation::EdgeMode::CHANGE_DIR) {
      anim.reversePastEdge();
    }
    comp.progress = anim.getProgress();
    comp.speed = anim.getSpeed();
  }
}
