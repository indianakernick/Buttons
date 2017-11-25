//
//  lock rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "lock rendering system.hpp"

#include "nvg helper.hpp"
#include "lock component.hpp"
#include "render polygon.hpp"
#include "transform component.hpp"
#include "activation component.hpp"
#include "lock rendering component.hpp"

void lockRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  const auto view = registry.view<Lock, Transform, Activation, LockRendering>();
  for (const EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, nvgRGBf(0.0f, 1.0f, 0.0f));
    
    nvgRect(ctx, -0.5f, 0.0f, 1.0f, 1.0f);
    
    if (isInactive(view.get<Activation>(entity).state)) {
      nvgTranslate(ctx, 0.0f, 0.5f);
      nvgPathWinding(ctx, NVG_HOLE);
      renderPolygon(ctx, view.get<Lock>(entity).index + 3, 0.4f, NVG_PI / 2.0f);
    }
    
    nvgFill(ctx);
    
    nvgRestore(ctx);
  }
}
