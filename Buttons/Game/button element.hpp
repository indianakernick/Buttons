//
//  button element.hpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef button_element_hpp
#define button_element_hpp

#include "nanovg.hpp"
#include "element rect.hpp"

struct ButtonStyle {
  ButtonStyle() = default;

  NVGcolor top = nvgRGBf(0.5f, 0.5f, 0.5f);
  NVGcolor bottom = nvgRGBf(0.5f, 0.5f, 0.5f);
  float cornerRadius = 0.0f;
};

class ButtonElement {
public:
  ButtonElement() = default;
  
  void rect(glm::vec2, glm::vec2);
  void rect(ElementRect);
  ElementRect rect() const;
  
  void style(const ButtonStyle &);
  ButtonStyle style() const;

  bool hit(glm::vec2) const;

  void render(NVGcontext *);
  
private:
  ButtonStyle mStyle;
  ElementRect mRect;
};

#endif
