//
//  json helper.hpp
//  Buttons
//
//  Created by Indi Kernick on 1/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef json_helper_hpp
#define json_helper_hpp

#include "json.hpp"
#include <glm/vec2.hpp>
#include "json helper.hpp"

using nlohmann::json;

void checkType(const json &, json::value_t);

template <typename T>
void getOptional(T &dst, const json &node, const char *name) {
  const auto iter = node.find(name);
  if (iter != node.cend()) {
    dst = iter->get<T>();
  }
}

struct b2Vec2;
extern "C" struct NVGcolor;

void from_json(const json &j, glm::vec2 &);
void from_json(const json &j, b2Vec2 &);
void from_json(const json &, NVGcolor &);

#endif
