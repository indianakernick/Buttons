//
//  platform rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 11/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "platform rendering system.hpp"

#include "nvg helper.hpp"
#include "transform component.hpp"
#include "platform rendering component.hpp"

void platformRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  auto view = registry.view<PlatformRendering, Transform>();
  for (EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, nvgRGBf(0.2f, 0.2f, 0.2f));
    nvgRect(ctx, 0.0f, 0.0f, 1.0f, 1.0f);
    nvgFill(ctx);
    
    nvgRestore(ctx);
  }
}
