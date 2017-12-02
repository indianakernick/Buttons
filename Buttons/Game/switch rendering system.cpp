//
//  switch rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 12/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "switch rendering system.hpp"

#include "nvg helper.hpp"
#include "transform component.hpp"
#include "activation component.hpp"
#include <Simpleton/Math/vectors.hpp>
#include "switch rendering component.hpp"

void switchRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  const auto view = registry.view<Transform, Activation, SwitchRendering>();
  for (const EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    
    const float activity = view.get<Activation>(entity).activity;
    const float angle = NVG_PI * 0.75f - activity * NVG_PI / 2.0f;
    glm::vec2 lineEnd = Math::angleMag(angle, std::cos(NVG_PI / 4.0));
    lineEnd += glm::vec2(0.5f, 0.0f);
    
    nvgBeginPath(ctx);
    nvgStrokeColor(ctx, nvgRGBf(0.4f, 0.4f, 0.4f));
    nvgStrokeWidth(ctx, 0.08f);
    nvgMoveTo(ctx, 0.5f, 0.0f);
    nvgLineTo(ctx, lineEnd);
    nvgStroke(ctx);
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, nvgRGBf(1.0f, 0.0f, 0.0f));
    nvgCircle(ctx, lineEnd, 0.08f);
    nvgFill(ctx);
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, nvgRGBf(0.6f, 0.6f, 0.6f));
    nvgArc(ctx, 0.5f, 0.0f, 0.25f, 0.0f, NVG_PI, NVG_CW);
    nvgClosePath(ctx);
    nvgFill(ctx);
    
    nvgRestore(ctx);
  }
}
