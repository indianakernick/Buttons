//
//  text element.hpp
//  Buttons
//
//  Created by Indi Kernick on 27/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef text_element_hpp
#define text_element_hpp

#include <string>
#include "nanovg.hpp"
#include "element.hpp"
#include "rendering resources.hpp"

struct TextStyle {
  TextStyle() = default;
  
  FontHandle font = nullptr;
  NVGcolor color = nvgRGBf(1.0f, 1.0f, 1.0f);
  float size = 0.0f;
};

class TextElement final : public Element {
public:
  TextElement() = default;
  
  void style(const TextStyle &);
  TextStyle style() const;
  
  void text(const std::string &);
  std::string text() const;
  
  void nullFont();
  
  void render(NVGcontext *) const override;
  
private:
  std::string mText;
  TextStyle mStyle;
};

#endif
