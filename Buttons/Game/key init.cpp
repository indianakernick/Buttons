//
//  key init.cpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "key init.hpp"

#include "yaml helper.hpp"
#include "player keys component.hpp"

void KeyInit::init(Key &key, const YAML::Node &node) {
  key.index = getChild(node, "index").as<uint16_t>();
  if (key.index >= MAX_KEYS) {
    throw std::runtime_error("Key index out of range");
  }
}
