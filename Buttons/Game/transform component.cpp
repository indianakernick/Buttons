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

namespace {
  float angleFromFile(const float angle) {
    return -glm::radians(angle);
  }
}

Transform::Transform(const YAML::Node &node, const EntityIDmap &) {
  if (const YAML::Node &posNode = node["pos"]) {
    pos = posNode.as<glm::vec2>();
  }
  if (const YAML::Node &scaleNode = node["scale"]) {
    scale = scaleNode.as<glm::vec2>();
  }
  if (const YAML::Node &rotationNode = node["rotation"]) {
    rotation = angleFromFile(rotationNode.as<float>());
  }
}

glm::mat3 getMat3(const Transform t) {
  return glm::scale(glm::rotate(glm::translate({}, t.pos), t.rotation), t.scale);
}
