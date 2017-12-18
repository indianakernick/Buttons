//
//  button element.hpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef button_element_hpp
#define button_element_hpp

#include <functional>
#include "element.hpp"

enum class MouseButtonState {
  RELEASED, // SDL_RELEASED
  PRESSED   // SDL_PRESSED
};

class ButtonElement final : public Element {
public:
  using Listener = std::function<void (ButtonElement &, MouseButtonState)>;

  ButtonElement() = default;

  bool hit(glm::vec2) const;

  void render(SDL_Renderer *) const override;
  bool handleMouseButton(const SDL_MouseButtonEvent &, const glm::mat3 &) override;
  
  void onMouseButton(const Listener &);
  
private:
  Listener listener;
};

#endif
