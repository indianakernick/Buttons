//
//  activation component.cpp
//  Buttons
//
//  Created by Indi Kernick on 9/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "activation component.hpp"

#include "yaml helper.hpp"

Activation::Activation(const YAML::Node &node, const EntityIDmap &) {
  getOptional(speed, node, "speed");
}
