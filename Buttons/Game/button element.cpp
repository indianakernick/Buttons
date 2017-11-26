//
//  button element.cpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "button element.hpp"

#include "nvg helper.hpp"
#include <glm/gtx/matrix_transform_2d.hpp>

ButtonElement::ButtonElement()
  : top(nvgRGBf(0.0f, 0.0f, 0.0f)),
    bottom(nvgRGBf(0.0f, 0.0f, 0.0f)),
    textColor(nvgRGBf(1.0f, 1.0f, 1.0f)) {}

void ButtonElement::setCenterSize(const glm::vec2 center, const glm::vec2 size) {
  rect.center = center;
  rect.halfSize = size / 2.0f;
}

void ButtonElement::setText(const std::string &newText) {
  text = newText;
}

void ButtonElement::setFont(const FontHandle newFont) {
  font = newFont;
}

void ButtonElement::setFontSize(const float newFontSize) {
  fontSize = newFontSize;
}

void ButtonElement::setTextColor(const NVGcolor color) {
  textColor = color;
}

void ButtonElement::setTopColor(const NVGcolor color) {
  top = color;
}

void ButtonElement::setBottomColor(const NVGcolor color) {
  bottom = color;
}

void ButtonElement::setCornerRadius(const float radius) {
  cornerRadius = std::abs(radius);
}

void ButtonElement::swapColors() {
  std::swap(top, bottom);
}

bool ButtonElement::hit(const glm::vec2 pos) const {
  return rect.encloses(pos);
}

namespace {
  glm::mat3 getMat(const Math::RectCS<float> rect) {
    return glm::scale(
      glm::translate(
        {},
        -rect.center
      ),
      glm::vec2(0.02f, -0.02f)
    );
  }
}

void ButtonElement::render(NVGcontext *const ctx) {
  nvgSave(ctx);
  
  nvgBeginPath(ctx);
  nvgFillPaint(ctx, nvgLinearGradient(
    ctx,
    0.0f, rect.top(),
    0.0f, rect.bottom(),
    top,
    bottom
  ));
  nvgRoundedRect(
    ctx,
    rect.left(), rect.bottom(),
    rect.halfSize.x * 2.0f, rect.halfSize.y * 2.0f,
    cornerRadius
  );
  nvgFill(ctx);
  
  nvgTransform(ctx, getMat(rect));
  
  nvgFontFaceId(ctx, font->id);
  nvgFillColor(ctx, textColor);
  nvgTextAlign(ctx, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
  nvgFontSize(ctx, fontSize);
  nvgText(ctx, 0.0f, 0.0f, text.c_str(), text.c_str() + text.size());
  
  nvgRestore(ctx);
}
