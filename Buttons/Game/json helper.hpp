//
//  json helper.hpp
//  Buttons
//
//  Created by Indi Kernick on 1/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef json_helper_hpp
#define json_helper_hpp

#include <json.hpp>
#include <glm/vec2.hpp>

using nlohmann::json;

template <typename T>
void getOptional(T &dst, const json &node, const char *name) {
  const auto iter = node.find(name);
  if (iter != node.cend()) {
    dst = iter->get<T>();
  }
}

struct b2Vec2;

namespace glm {
  void from_json(const json &j, glm::vec2 &);
}
void from_json(const json &j, b2Vec2 &);

#endif
