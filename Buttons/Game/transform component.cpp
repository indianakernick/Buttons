//
//  transform component.cpp
//  Buttons
//
//  Created by Indi Kernick on 9/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "transform component.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/matrix_transform_2d.hpp>

glm::mat3 getMat3(const Transform t) {
  static constexpr glm::mat3 I = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
  };
  return glm::scale(glm::rotate(glm::translate(I, t.pos), t.rotation), t.scale);
}
