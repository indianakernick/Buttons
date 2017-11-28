//
//  button element.cpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "button element.hpp"

#include <SDL2/SDL_events.h>
#include <Simpleton/Camera 2D/matrix mul.hpp>

void ButtonElement::style(const ButtonStyle &style) {
  mStyle = style;
}

ButtonStyle ButtonElement::style() const {
  return mStyle;
}

bool ButtonElement::hit(const glm::vec2 pos) const {
  return mRect.encloses(pos);
}

void ButtonElement::render(NVGcontext *const ctx) const {
  nvgSave(ctx);
  
  nvgBeginPath(ctx);
  nvgFillPaint(ctx, nvgLinearGradient(
    ctx,
    0.0f, mRect.top(),
    0.0f, mRect.bottom(),
    mStyle.top,
    mStyle.bottom
  ));
  nvgRoundedRect(
    ctx,
    mRect.left(), mRect.bottom(),
    mRect.halfSize.x * 2.0f, mRect.halfSize.y * 2.0f,
    mStyle.cornerRadius
  );
  nvgFill(ctx);
  
  nvgRestore(ctx);
}

bool ButtonElement::handleMouseButton(const SDL_MouseButtonEvent &e, const glm::mat3 &toMeters) {
  if (hit(Cam2D::mulPos(toMeters, {e.x, e.y}))) {
    if (listener) {
      listener(*this, static_cast<MouseButtonState>(e.state));
      return true;
    }
  }
  return false;
}

void ButtonElement::onMouseButton(const Listener &newListener) {
  listener = newListener;
}
