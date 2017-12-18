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
#include <functional>
#include "element.hpp"

struct ButtonStyle {
  ButtonStyle() = default;

  NVGcolor top = nvgRGBf(0.5f, 0.5f, 0.5f);
  NVGcolor bottom = nvgRGBf(0.5f, 0.5f, 0.5f);
  float cornerRadius = 0.0f;
};

enum class MouseButtonState {
  RELEASED, // SDL_RELEASED
  PRESSED   // SDL_PRESSED
};

class ButtonElement final : public Element {
public:
  using Listener = std::function<void (ButtonElement &, MouseButtonState)>;

  ButtonElement() = default;
  
  void style(const ButtonStyle &);
  ButtonStyle style() const;

  bool hit(glm::vec2) const;

  void render(NVGcontext *) const override;
  bool handleMouseButton(const SDL_MouseButtonEvent &, const glm::mat3 &) override;
  
  void onMouseButton(const Listener &);
  
private:
  ButtonStyle mStyle;
  Listener listener;
};

#endif
