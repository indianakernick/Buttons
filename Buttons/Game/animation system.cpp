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
  
  for (const EntityID entity : view) {
    using Edge = Animation::EdgeMode;
    
    Animation &comp = view.get(entity);
    Time::ProgSpeedAnim<float> anim(comp.progress, comp.speed);
    anim.advance(delta);
    
    if (comp.edgeMode == Edge::STOP) {
      anim.stopOnEdge();
    } else if (comp.edgeMode == Edge::REPEAT) {
      anim.repeatPastEdge();
    } else if (comp.edgeMode == Edge::CHANGE_DIR) {
      anim.reversePastEdge();
    }
    
    comp.progress = anim.getProgress();
    comp.speed = anim.getSpeed();
  }
}
