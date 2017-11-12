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
#include <Simpleton/Math/interpolate.hpp>

void doorRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  auto view = registry.view<DoorRendering, Transform, Activation>();
  for (EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    
    using ToVec = Math::ToVec<float, Math::Dir::RIGHT, Math::Dir::UP>;
    const Math::Dir closeDir = view.get<DoorRendering>(entity).closeDir;
    const glm::vec2 closeVec = ToVec::conv(closeDir);
    const glm::vec2 closeAxis = Math::isHori(closeDir)
                              ? glm::vec2(1.0f, 0.0f)
                              : glm::vec2(0.0f, 1.0f);
    const glm::vec2 activity(Math::cubicInOut(view.get<Activation>(entity).activity));
    nvgTranslate(ctx, closeVec * -0.5f);
    nvgScale(ctx, glm::vec2(1.0f) - closeAxis * activity);
    nvgTranslate(ctx, closeVec * 0.5f);
    
    nvgBeginPath(ctx);
    nvgFillColor(ctx, nvgRGBf(0.0f, 0.0f, 1.0f));
    nvgRect(ctx, -0.5f, -0.5f, 1.0f, 1.0f);
    nvgFill(ctx);
    
    nvgRestore(ctx);
  }
}
