//
//  button.cpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "button.hpp"

#include "nvg helper.hpp"
#include <glm/gtx/matrix_transform_2d.hpp>

Button::Button(const glm::vec2 min, const glm::vec2 max)
  : top(nvgRGBf(0.0f, 0.0f, 0.0f)),
    bottom(nvgRGBf(0.0f, 0.0f, 0.0f)),
    bounds(min, max) {}

void Button::setText(const std::string &newText) {
  text = newText;
}

void Button::setFont(const FontHandle newFont) {
  font = newFont;
}

void Button::setFontSize(const float newFontSize) {
  fontSize = newFontSize;
}

void Button::setTopColor(const NVGcolor color) {
  top = color;
}

void Button::setBottomColor(const NVGcolor color) {
  bottom = color;
}

void Button::setCornerRadius(const float radius) {
  cornerRadius = std::abs(radius);
}

void Button::swapColors() {
  std::swap(top, bottom);
}

bool Button::hit(const glm::vec2 pos) const {
  return bounds.encloses(pos);
}

namespace {
  glm::mat3 getMat(const Math::RectPP<float> rect) {
    return glm::scale(
      glm::translate(
        {},
        glm::vec2(-rect.min.x, -rect.max.y)
      ),
      rect.size() * glm::vec2(0.001f, -0.001f)
    );
  }
}

void Button::render(NVGcontext *const ctx) {
  nvgSave(ctx);

  nvgTransform(ctx, getMat(bounds));
  
  nvgBeginPath(ctx);
  nvgFillPaint(ctx, nvgLinearGradient(
    ctx,
    0.0f, 0.0f,
    0.0f, 1000.0f,
    top,
    bottom
  ));
  nvgRoundedRect(ctx, 0.0f, 0.0f, 1000.0f, 1000.0f, cornerRadius);
  nvgFill(ctx);
  
  nvgFontFaceId(ctx, font->id);
  nvgFillColor(ctx, nvgRGBf(1.0f, 1.0f, 1.0f));
  nvgTextAlign(ctx, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
  nvgFontSize(ctx, fontSize);
  nvgText(ctx, 0.0f, 0.0f, text.c_str(), text.c_str() + text.size());
  
  nvgRestore(ctx);
}
