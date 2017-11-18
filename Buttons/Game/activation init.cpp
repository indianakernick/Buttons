//
//  activation init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "activation init.hpp"

#include "yaml helper.hpp"

void ActivationInit::init(Activation &comp, const YAML::Node &node, const EntityIDmap &, EntityID) {
  getOptional(comp.speed, node, "speed");
}
