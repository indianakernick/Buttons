//
//  moving platform rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 16/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "moving platform rendering system.hpp"

#include "nvg helper.hpp"
#include "transform component.hpp"
#include "moving platform rendering component.hpp"

void movingPlatformRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  auto view = registry.view<MovingPlatformRendering, Transform>();
  for (EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, nvgRGBf(0.3f, 0.3f, 0.3f));
    nvgRect(ctx, -0.5f, -0.5f, 1.0f, 1.0f);
    nvgFill(ctx);
    
    nvgRestore(ctx);
  }
}
