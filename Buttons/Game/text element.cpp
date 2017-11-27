//
//  text element.cpp
//  Buttons
//
//  Created by Indi Kernick on 27/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "text element.hpp"

#include "nvg helper.hpp"
#include <glm/gtx/matrix_transform_2d.hpp>

void TextElement::rect(const glm::vec2 center, const glm::vec2 size) {
  mRect.center = center;
  mRect.halfSize = size / 2.0f;
}

void TextElement::rect(const ElementRect rect) {
  mRect = rect;
}

ElementRect TextElement::rect() const {
  return mRect;
}

void TextElement::style(const TextStyle &style) {
  mStyle = style;
}

TextStyle TextElement::style() const {
  return mStyle;
}

void TextElement::text(const std::string &text) {
  mText = text;
}

std::string TextElement::text() const {
  return mText;
}

void TextElement::nullFont() {
  mStyle.font = nullptr;
}

namespace {
  glm::mat3 getMat(const ElementRect rect) {
    return glm::scale(
      glm::translate(
        glm::scale({}, glm::vec2(1.0f, -1.0f)),
        -rect.center
      ),
      glm::vec2(0.02f, 0.02f)
    );
  }
}

void TextElement::render(NVGcontext *const ctx) const {
  nvgSave(ctx);

  nvgTransform(ctx, getMat(mRect));
  
  nvgFontFaceId(ctx, mStyle.font->id);
  nvgFillColor(ctx, mStyle.color);
  nvgTextAlign(ctx, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
  nvgFontSize(ctx, mStyle.size);
  nvgText(ctx, 0.0f, 0.0f, mText.c_str(), mText.c_str() + mText.size());
  
  nvgRestore(ctx);
}
