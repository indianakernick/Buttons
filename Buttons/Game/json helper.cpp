//
//  json helper.cpp
//  Buttons
//
//  Created by Indi Kernick on 1/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "json helper.hpp"

void checkType(const json &node, const json::value_t type) {
  if (node.type() != type) {
    throw std::runtime_error("Node is wrong type: " + node.type_name());
  }
}
