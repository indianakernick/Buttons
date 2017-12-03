//
//  player rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 11/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "player rendering system.hpp"

#include "nvg helper.hpp"
#include "transform component.hpp"
#include "player rendering component.hpp"

void playerRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  auto view = registry.view<PlayerRendering, Transform>();
  for (const EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, nvgRGBf(1.0f, 1.0f, 1.0f));
    nvgCircle(ctx, 0.5f, 0.5f, 0.5f);
    nvgFill(ctx);
    
    nvgRestore(ctx);
  }
}
