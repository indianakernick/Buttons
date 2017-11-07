//
//  transform component.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef transform_component_hpp
#define transform_component_hpp

#include <glm/vec2.hpp>

struct Transform {
  glm::vec2 pos;
  glm::vec2 scale;
  float angle;
};

#endif
