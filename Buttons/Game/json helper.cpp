//
//  json helper.cpp
//  Buttons
//
//  Created by Indi Kernick on 1/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "json helper.hpp"

void glm::from_json(const json &j, glm::vec2 &vec) {
  vec.x = j.at(0).get<float>();
  vec.y = j.at(1).get<float>();
}

void from_json(const json &j, b2Vec2 &vec) {
  vec.x = j.at(0).get<float>();
  vec.y = j.at(1).get<float>();
}
