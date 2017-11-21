//
//  text rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 20/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "text rendering system.hpp"

#include "nvg helper.hpp"
#include "text component.hpp"
#include "transform component.hpp"
#include "text rendering component.hpp"

#include <iostream>

void textRenderingSystem(Registry &registry, NVGcontext *const ctx) {
  const auto view = registry.view<Transform, Text, TextRendering>();
  for (const EntityID entity : view) {
    nvgSave(ctx);
    
    nvgTransform(ctx, getMat3(view.get<Transform>(entity)));
    nvgScale(ctx, 1.0f, -1.0f);
    
    const TextRendering &format = view.get<TextRendering>(entity);
    const std::string &text = view.get<Text>(entity).text;

    nvgFontFaceId(ctx, 0);
    nvgFillColor(ctx, format.color);
    nvgTextAlign(ctx, format.align);
    nvgFontSize(ctx, format.size);
    nvgText(ctx, 0.0f, 0.0f, text.c_str(), text.c_str() + text.size());
  
    nvgRestore(ctx);
  }
}
