//
//  element.hpp
//  Buttons
//
//  Created by Indi Kernick on 27/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef element_hpp
#define element_hpp

#include "element rect.hpp"

extern "C" struct NVGcontext;

class Element {
public:
  Element() = default;
  virtual ~Element() = default;
  
  void rect(glm::vec2, glm::vec2);
  void rect(ElementRect);
  ElementRect rect() const;

  virtual void render(NVGcontext *) const = 0;

protected:
  ElementRect mRect;
};

#endif
