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

namespace {
  constexpr float BASE_WIDTH = 1.4f;
  constexpr float BASE_HEIGHT = 0.15f;
}

void buttonRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  const auto view = registry.view<Activation, Transform, ButtonRendering>();
  for (const EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    
    nvgSave(ctx);
    
    nvgScale(ctx, 1.0f, 1.0f - view.get<Activation>(entity).activity);
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, nvgRGBf(1.0f, 0.0f, 0.0f));
    nvgRect(ctx, -0.5f, 0.0f, 1.0f, 0.25f);
    nvgFill(ctx);
    
    nvgRestore(ctx);
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, nvgRGBf(0.6f, 0.6f, 0.6f));
    nvgRect(ctx, -BASE_WIDTH / 2.0f, 0.0f, BASE_WIDTH, -BASE_HEIGHT);
    nvgFill(ctx);
    
    nvgRestore(ctx);
  }
}
