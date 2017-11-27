//
//  element.cpp
//  Buttons
//
//  Created by Indi Kernick on 27/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "element.hpp"

void Element::rect(const glm::vec2 center, const glm::vec2 size) {
  mRect.center = center;
  mRect.halfSize = size / 2.0f;
}

void Element::rect(const ElementRect rect) {
  mRect = rect;
}

ElementRect Element::rect() const {
  return mRect;
}
