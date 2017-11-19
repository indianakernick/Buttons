//
//  laser emitter rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 19/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "laser emitter rendering system.hpp"

#include "nvg helper.hpp"
#include "b2 glm cast.hpp"
#include "physics component.hpp"
#include "transform component.hpp"
#include "activation component.hpp"

void laserEmitterRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  const auto view = registry.view<PhysicsRayCast, Transform, Activation>();
  for (const EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, nvgRGBf(0.6f, 0.6f, 0.6f));
    nvgMoveTo(ctx, -0.5f, 0.0f);
    nvgLineTo(ctx, 0.5f, 0.0f);
    nvgLineTo(ctx, 0.5f, 0.5f);
    nvgLineTo(ctx, 0.25f, 0.5f);
    nvgLineTo(ctx, 0.25f, 1.0f);
    nvgLineTo(ctx, -0.25f, 1.0f);
    nvgLineTo(ctx, -0.25f, 0.5f);
    nvgLineTo(ctx, -0.5f, 0.5f);
    nvgClosePath(ctx);
    nvgFill(ctx);
    
    nvgRestore(ctx);
    
    if (view.get<Activation>(entity).state == Activation::State::ACTIVE) {
      const PhysicsRayCast &rayCast = view.get<PhysicsRayCast>(entity);
      const glm::vec2 start = castToGLM(rayCast.start);
      const glm::vec2 end = castToGLM(rayCast.start + rayCast.closestFraction * (rayCast.end - rayCast.start));
      
      nvgBeginPath(ctx);
      nvgStrokeWidth(ctx, 0.1f);
      nvgStrokeColor(ctx, nvgRGBf(1.0f, 0.0f, 0.0f));
      nvgMoveTo(ctx, start);
      nvgLineTo(ctx, end);
      nvgStroke(ctx);
    }
  }
}
