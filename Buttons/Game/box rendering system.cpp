//
//  box rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 11/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "box rendering system.hpp"

#include "nvg helper.hpp"
#include "transform component.hpp"
#include "box rendering component.hpp"

namespace {
  constexpr float STROKE_WIDTH = 0.1f;
}

void boxRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  nvgSave(ctx);
  
  nvgStrokeColor(ctx, nvgRGB(107, 68, 35));
  nvgFillColor(ctx, nvgRGB(193, 154, 107));

  auto view = registry.view<BoxRendering, Transform>();
  for (EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    nvgScissor(ctx, -0.5f, -0.5f, 1.0f, 1.0f);
    
    nvgBeginPath(ctx);
    nvgStrokeWidth(ctx, STROKE_WIDTH);
    nvgMoveTo(ctx, -0.5f, -0.5f);
    nvgLineTo(ctx, 0.5f, -0.5f);
    nvgLineTo(ctx, 0.5f, 0.5f);
    nvgLineTo(ctx, -0.5f, 0.5f);
    nvgClosePath(ctx);
    nvgFill(ctx);
    nvgStroke(ctx);
    
    nvgBeginPath(ctx);
    nvgStrokeWidth(ctx, STROKE_WIDTH / 2.0f);
    nvgMoveTo(ctx, -0.5f, -0.5f);
    nvgLineTo(ctx, 0.5f, 0.5f);
    nvgMoveTo(ctx, 0.5f, -0.5f);
    nvgLineTo(ctx, -0.5f, 0.5f);
    nvgStroke(ctx);
    
    nvgRestore(ctx);
  }
  
  nvgRestore(ctx);
}
