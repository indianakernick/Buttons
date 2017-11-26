//
//  shadow rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "shadow rendering system.hpp"

#include "nvg helper.hpp"
#include "transform component.hpp"
#include "activation component.hpp"
#include "shadow rendering component.hpp"

void shadowRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  const auto view = registry.view<Transform, Activation, ShadowRendering>();
  for (const EntityID entity : view) {
    const Activation activation = view.get<Activation>(entity);
    if (activation.state == Activation::State::ACTIVE) {
      continue;
    }
    
    const float activity = activation.activity;
    
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    
    nvgBeginPath(ctx);
    nvgFillPaint(ctx, nvgBoxGradient(
      ctx,
      0.0f, 0.0f, //pos
      1.0f, 1.0f, //size
      0.05f, //radius
      0.05f, //feather
      nvgGrayA(activity),
      nvgGrayA(0.0f)
    ));
    nvgRect(ctx, 0.0f, 0.0f, 1.0f, 1.0f);
    nvgFill(ctx);
    
    nvgRestore(ctx);
  }
}
