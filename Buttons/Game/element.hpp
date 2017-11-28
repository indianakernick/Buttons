//
//  element.hpp
//  Buttons
//
//  Created by Indi Kernick on 27/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef element_hpp
#define element_hpp

#include <glm/mat3x3.hpp>
#include "element rect.hpp"

extern "C" struct SDL_MouseButtonEvent;
extern "C" struct NVGcontext;

class Element {
public:
  Element() = default;
  virtual ~Element() = default;
  
  void rect(glm::vec2, glm::vec2);
  void rect(ElementRect);
  ElementRect rect() const;

  virtual void render(NVGcontext *) const = 0;
  virtual bool handleMouseButton(const SDL_MouseButtonEvent &, const glm::mat3 &);

protected:
  ElementRect mRect;
};

#endif
