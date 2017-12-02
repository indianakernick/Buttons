//
//  json helper.cpp
//  Buttons
//
//  Created by Indi Kernick on 1/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "json helper.hpp"

#include "nanovg.hpp"
#include "b2 glm cast.hpp"

void checkType(const json &node, const json::value_t type) {
  if (node.type() != type) {
    throw std::runtime_error("Node is wrong type: " + node.type_name());
  }
}

void glm::from_json(const json &j, glm::vec2 &vec) {
  vec.x = j.at(0).get<float>();
  vec.y = j.at(1).get<float>();
}

void from_json(const json &j, b2Vec2 &vec) {
  glm::vec2 glmVec;
  from_json(j, glmVec);
  vec = castToB2(glmVec);
}

void from_json(const json &j, NVGcolor &color) {
  color.r = j.at(0).get<float>();
  color.g = j.at(1).get<float>();
  color.b = j.at(2).get<float>();
  if (j.size() >= 4) {
    color.a = j[3].get<float>();
  } else {
    color.a = 1.0f;
  }
}
