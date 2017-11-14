//
//  transform component.cpp
//  Buttons
//
//  Created by Indi Kernick on 9/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "transform component.hpp"

#include "yaml helper.hpp"
#include <glm/trigonometric.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>

Transform::Transform(const YAML::Node &node, const EntityIDmap &) {
  getOptional(pos, node, "pos");
  getOptional(scale, node, "scale");
  getOptional(rotation, node, "rotation");
  rotation = -glm::radians((rotation));
}

glm::mat3 getMat3(const Transform t) {
  return glm::scale(glm::rotate(glm::translate({}, t.pos), t.rotation), t.scale);
}
