//
//  key rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "key rendering system.hpp"

#include "nvg helper.hpp"
#include "key component.hpp"
#include "render polygon.hpp"
#include "transform component.hpp"
#include "activation component.hpp"
#include "key rendering component.hpp"

void keyRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  const auto view = registry.view<Key, Transform, Activation, KeyRendering>();
  for (const EntityID entity : view) {
    if (isInactive(view.get<Activation>(entity).state)) {
      continue;
    }
    
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    nvgTranslate(ctx, 0.5f, 0.5f);
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, nvgRGBf(0.0f, 1.0f, 0.0));
    renderPolygon(ctx, view.get<Key>(entity).index + 3, 0.4f, NVG_PI / 2.0f);
    nvgFill(ctx);
    
    nvgRestore(ctx);
  }
}
