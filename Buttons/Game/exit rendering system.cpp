//
//  exit rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 14/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "exit rendering system.hpp"

#include "nvg helper.hpp"
#include "transform component.hpp"
#include "animation component.hpp"
#include "exit rendering component.hpp"

namespace {
  const NVGcolor FIRST_COLOR = nvgRGBf(0.25f, 0.25f, 1.0f);
  const NVGcolor SECOND_COLOR = nvgRGBf(0.0f, 0.0f, 0.75f);
  
  void square(
    NVGcontext *const ctx,
    const NVGcolor color,
    const float thickness,
    const float size
  ) {
    static const glm::vec2 CENTER = {0.0f, 0.5f};
    
    auto transform = [] (const float x, const float y) {
      return glm::vec2(x, y) + CENTER;
    };
    
    const float outer = size / 2.0f;
    const float inner = outer - thickness;
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, color);
    
    nvgMoveTo(ctx, transform(-outer, -outer));
    nvgLineTo(ctx, transform(-outer, outer));
    nvgLineTo(ctx, transform(outer, outer));
    nvgLineTo(ctx, transform(outer, -outer));
    nvgLineTo(ctx, transform(-inner, -outer));
    nvgLineTo(ctx, transform(-inner, -inner));
    nvgLineTo(ctx, transform(inner, -inner));
    nvgLineTo(ctx, transform(inner, inner));
    nvgLineTo(ctx, transform(-inner, inner));
    nvgLineTo(ctx, transform(-inner, -outer));
    nvgClosePath(ctx);
    
    nvgFill(ctx);
  }
}

void exitRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  const auto view = registry.view<Transform, Animation, ExitRendering>();
  for (const EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    
    float prog = 1.0f - view.get<Animation>(entity).progress;
    
    if (prog > 0.5f) {
      prog = (prog - 0.5f) * 2.0f;
      
      nvgBeginPath(ctx);
      nvgFillColor(ctx, SECOND_COLOR);
      nvgRect(ctx, -0.5f, 0.0f, 1.0f, 1.0f);
      nvgFill(ctx);
      square(ctx, FIRST_COLOR, 0.1f, prog * 0.2f + 0.8f);
      square(ctx, FIRST_COLOR, 0.1f, prog * 0.2f + 0.4f);
      square(ctx, FIRST_COLOR, 0.1f, prog * 0.2f);
    } else {
      prog = prog * 2.0f;
      
      nvgBeginPath(ctx);
      nvgFillColor(ctx, FIRST_COLOR);
      nvgRect(ctx, -0.5f, 0.0f, 1.0f, 1.0f);
      nvgFill(ctx);
      square(ctx, SECOND_COLOR, 0.1f, prog * 0.2f + 0.8f);
      square(ctx, SECOND_COLOR, 0.1f, prog * 0.2f + 0.4f);
      square(ctx, SECOND_COLOR, 0.1f, prog * 0.2f);
    }
    
    nvgRestore(ctx);
  }
}
