//
//  transform init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "transform init.hpp"

#include <glm/trigonometric.hpp>

void TransformInit::init(Transform &comp, const json &node) {
  getOptional(comp.pos, node, "pos");
  getOptional(comp.scale, node, "scale");
  getOptional(comp.rotation, node, "rotation");
  comp.rotation = glm::radians(comp.rotation);
}
