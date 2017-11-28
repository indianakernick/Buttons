//
//  element manager.hpp
//  Buttons
//
//  Created by Indi Kernick on 28/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef element_manager_hpp
#define element_manager_hpp

#include <vector>
#include <memory>
#include "element.hpp"
#include <glm/mat3x3.hpp>
#include "input dispatcher.hpp"

class ElementManager {
public:
  ElementManager() = default;
  
  bool handleEvent(const SDL_Event &, const glm::mat3 &);
  void render(NVGcontext *);
  
  void addElement(std::unique_ptr<Element> &&);
  void remAllElements();
  
private:
  std::vector<std::unique_ptr<Element>> elements;
};

#endif
