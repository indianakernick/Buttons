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

void doorRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  auto view = registry.view<DoorRendering, Transform, Activation>();
  for (EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    
    using ToVec = Math::ToVec<float, Math::Dir::RIGHT, Math::Dir::UP>;
    const Math::Dir closeDir = view.get<DoorRendering>(entity).closeDir;
    const glm::vec2 activity(view.get<Activation>(entity).activity);
    //Hmm...
    nvgScale(ctx, 1.0f, 1.0f - view.get<Activation>(entity).activity);
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, nvgRGBf(0.0f, 0.0f, 1.0f));
    nvgRect(ctx, -0.5f, -0.5f, 1.0f, 1.0f);
    nvgFill(ctx);
    
    nvgRestore(ctx);
  }
}
