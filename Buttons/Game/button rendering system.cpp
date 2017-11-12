//
//  button rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 12/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "button rendering system.hpp"

#include "nvg helper.hpp"
#include "transform component.hpp"
#include "activation component.hpp"
#include "button rendering component.hpp"

void buttonRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  const auto view = registry.view<Activation, Transform, ButtonRendering>();
  for (EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    nvgScale(ctx, 1.0f, 1.0f - view.get<Activation>(entity).activity);
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, nvgRGBf(1.0f, 0.0f, 0.0f));
    nvgRect(ctx, -0.5f, 0.0f, 1.0f, 0.5f);
    nvgFill(ctx);
    
    nvgRestore(ctx);
  }
}
