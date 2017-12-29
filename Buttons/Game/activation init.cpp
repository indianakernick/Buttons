//
//  activation init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "activation init.hpp"

void ActivationInit::init(Activation &comp, const json &node) {
  Data::getOptional(comp.speed, node, "speed");
  if (JSON_OPTIONAL(activeNode, node, "active")) {
    if (activeNode->get<bool>()) {
      comp.state = Activation::State::ACTIVE;
      comp.activity = 1.0f;
    }
  }
}
