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
  const NVGcolor LIGHT_BLUE = nvgRGBf(0.25f, 0.25f, 1.0f);
  const NVGcolor DARK_BLUE = nvgRGBf(0.0f, 0.0f, 0.75f);
}

void exitRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  const auto view = registry.view<Transform, Animation, ExitRendering>();
  for (EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    
    const float prog = view.get<Animation>(entity).progress;
    const float halfProg = prog / 2.0f;
    const float quartProg = prog / 4.0f;
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, DARK_BLUE);
    nvgRect(ctx, -0.5f, 0.0f, 1.0f, 0.5f);
    nvgFill(ctx);
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, LIGHT_BLUE);
    nvgRect(ctx, -0.5f + halfProg, quartProg, 1.0f - prog, 0.5f - halfProg);
    nvgFill(ctx);
    
    //nvgBeginPath(ctx);
    //nvgFillColor(ctx, DARK_BLUE);
    //nvgRect(ctx, -0.5f + 0.1f + halfProg)
    
    nvgRestore(ctx);
  }
}
