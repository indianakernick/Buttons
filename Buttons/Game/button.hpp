//
//  button.hpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef button_hpp
#define button_hpp

#include <string>
#include "nanovg.hpp"
#include "rendering resources.hpp"
#include <Simpleton/Math/rect.hpp>

class Button {
public:
  Button();
  
  void setBounds(glm::vec2, glm::vec2);
  
  void setText(const std::string &);
  void setFont(FontHandle);
  void setFontSize(float);
  void setTextColor(NVGcolor);
  
  void setTopColor(NVGcolor);
  void setBottomColor(NVGcolor);
  void setCornerRadius(float);
  void swapColors();

  bool hit(glm::vec2) const;

  void render(NVGcontext *);
  
private:
  std::string text;
  FontHandle font;
  NVGcolor top;
  NVGcolor bottom;
  NVGcolor textColor;
  Math::RectPP<float> bounds;
  float cornerRadius = 0.0f;
  float fontSize = 0.0f;
};

#endif
