//
//  text init.cpp
//  Buttons
//
//  Created by Indi Kernick on 21/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "text init.hpp"

void TextInit::init(Text &text, const json &node) {
  text.text = node.get_ref<const std::string &>();
}
