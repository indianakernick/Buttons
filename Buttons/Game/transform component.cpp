//
//  transform component.cpp
//  Buttons
//
//  Created by Indi Kernick on 9/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "transform component.hpp"

#include "component init.hpp"
#include <glm/trigonometric.hpp>

namespace {
  float angleToFile(const float angle) {
    return -glm::degrees(angle);
  }

  float angleFromFile(const float angle) {
    return -glm::radians(angle);
  }
}

template <>
struct ComponentInit<Transform> {
  static void init(Transform &transform, const YAML::Node &node) {
    transform = {};
    if (const YAML::Node &posNode = node["pos"]) {
      transform.pos = posNode.as<glm::vec2>();
    }
    if (const YAML::Node &scaleNode = node["scale"]) {
      transform.scale = scaleNode.as<glm::vec2>();
    }
    if (const YAML::Node &rotationNode = node["rotation"]) {
      transform.rotation = angleFromFile(rotationNode.as<float>());
    }
  }
};
