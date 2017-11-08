//
//  object types.cpp
//  Buttons
//
//  Created by Indi Kernick on 8/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "object types.hpp"

void *getUserData(const std::string &objectTypeName) {
  try {
    return Utils::getValueByName<void *, ObjectTypes>("ObjectType::" + objectTypeName, [] (auto t) {
      return getUserData<UTILS_TYPE(t)>();
    });
  } catch (Utils::TypeNotFound &) {
    throw std::runtime_error("Invalid object type name");
  }
}
