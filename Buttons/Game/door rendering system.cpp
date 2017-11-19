//
//  door rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 12/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "door rendering system.hpp"

#include "nvg helper.hpp"
#include "transform component.hpp"
#include "activation component.hpp"
#include "door rendering component.hpp"
#include <Simpleton/Math/interpolate.hpp>

void doorRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  auto view = registry.view<DoorRendering, Transform, Activation>();
  for (const EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    const float activity = Math::cubicInOut(view.get<Activation>(entity).activity);
    nvgScale(ctx, 1.0f, 1.0f - activity);
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, nvgRGBf(0.0f, 0.0f, 1.0f));
    nvgRect(ctx, -0.5f, 0.0f, 1.0f, 1.0f);
    nvgFill(ctx);
    
    nvgRestore(ctx);
  }
}
