//
//  collision categories.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "collision categories.hpp"

uint16_t getCategoryBit(const std::string &categoryName) {
  try {
    return Utils::getValueByName<uint16_t, Categories>("Category::" + categoryName, [] (auto t) {
      return 1 << Utils::indexOf<Categories, UTILS_TYPE(t)>;
    });
  } catch (Utils::TypeNotFound &) {
    throw std::runtime_error("Invalid category name");
  }
}
