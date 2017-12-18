//
//  text element.cpp
//  Buttons
//
//  Created by Indi Kernick on 27/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "text element.hpp"

void TextElement::text(const std::string &text) {
  mText = text;
}

std::string TextElement::text() const {
  return mText;
}

void TextElement::render(SDL_Renderer *const ctx) const {
  
}
