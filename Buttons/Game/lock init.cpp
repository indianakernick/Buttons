//
//  lock init.cpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "lock init.hpp"

#include "player keys component.hpp"

void LockInit::init(Lock &lock, const json &node) {
  lock.index = node.at("index").get<uint8_t>();
  if (lock.index >= MAX_KEYS) {
    throw std::runtime_error("Lock index out of range");
  }
}
