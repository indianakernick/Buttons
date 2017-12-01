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

using json = nlohmann::json;

void checkType(const json &, json::value_t);

template <typename T>
void getOptional(T &dst, const json &node, const char *name) {
  const auto iter = node.find(name);
  if (iter != node.cend()) {
    dst = iter->get<T>();
  }
}

#endif
