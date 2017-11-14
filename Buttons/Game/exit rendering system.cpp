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
  
  void square(NVGcontext *const ctx, const NVGcolor color, const float size) {
    static const glm::vec2 CENTER = {0.0f, 0.25f};
    static const glm::vec2 SQUARE_SIZE = {1.0f, 0.5f};
    
    auto transform = [] (const float x, const float y) {
      return glm::vec2(x, y) * SQUARE_SIZE + CENTER;
    };
    
    const float halfSize = size / 2.0f;
    
    nvgBeginPath(ctx);
    nvgStrokeColor(ctx, color);
    nvgStrokeWidth(ctx, 0.1f);
    nvgMoveTo(ctx, transform(-halfSize, -halfSize));
    nvgLineTo(ctx, transform(-halfSize, halfSize));
    nvgLineTo(ctx, transform(halfSize, halfSize));
    nvgLineTo(ctx, transform(halfSize, -halfSize));
    nvgClosePath(ctx);
    nvgStroke(ctx);
  }
}

void exitRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  const auto view = registry.view<Transform, Animation, ExitRendering>();
  for (EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    
    const float prog = view.get<Animation>(entity).progress;
    
    square(ctx, FIRST_COLOR, 1.0f);
    square(ctx, SECOND_COLOR, std::fmod(1.0f - prog + 0.8f, 1.0f));
    square(ctx, FIRST_COLOR, std::fmod(1.0f - prog + 0.6f, 1.0f));
    square(ctx, SECOND_COLOR, std::fmod(1.0f - prog + 0.4f, 1.0f));
    square(ctx, FIRST_COLOR, std::fmod(1.0f - prog + 0.2f, 1.0f));
    square(ctx, SECOND_COLOR, std::fmod(1.0f - prog + 0.0f, 1.0f));
    
    nvgRestore(ctx);
  }
}
