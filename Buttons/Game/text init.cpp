//
//  text init.cpp
//  Buttons
//
//  Created by Indi Kernick on 21/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "text init.hpp"

#include "yaml helper.hpp"

void TextInit::init(Text &text, const YAML::Node &node) {
  getOptional(text.text, node, "text");
}
