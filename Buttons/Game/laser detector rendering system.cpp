//
//  laser detector rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 20/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "laser detector rendering system.hpp"

#include "nvg helper.hpp"
#include "transform component.hpp"
#include "activation component.hpp"
#include "laser detector rendering component.hpp"

void laserDetectorRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  const auto view = registry.view<Transform, Activation, LaserDetectorRendering>();
  for (const EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    
    nvgBeginPath(ctx);
    
    if (view.get<Activation>(entity).state == Activation::State::ACTIVE) {
      nvgFillColor(ctx, nvgRGBf(1.0f, 1.0f, 0.0));
    } else {
      nvgFillColor(ctx, nvgRGBf(0.5f, 0.5f, 0.5f));
    }
    
    nvgRect(ctx, 0.0f, 0.0f, 1.0f, 0.2f);
    nvgFill(ctx);
    
    nvgRestore(ctx);
  }
}
