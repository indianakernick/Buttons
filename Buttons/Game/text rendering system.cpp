//
//  text rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 20/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "text rendering system.hpp"

#include "nvg helper.hpp"
#include "transform component.hpp"
#include "text rendering component.hpp"

#include <iostream>

void textRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  const auto view = registry.view<Transform, TextRendering>();
  for (const EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    nvgScale(ctx, 1.0f, -1.0f);
    
    const TextRendering &comp = view.get<TextRendering>(entity);
    
    nvgFontFaceId(ctx, 0);
    nvgFillColor(ctx, comp.color);
    nvgTextAlign(ctx, comp.align);
    nvgFontSize(ctx, comp.size);
    nvgText(ctx, 0.0f, 0.0f, comp.text.c_str(), comp.text.c_str() + comp.text.size());
  
    nvgRestore(ctx);
  }
}
