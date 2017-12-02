//
//  activation init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "activation init.hpp"

void ActivationInit::init(Activation &comp, const json &node) {
  getOptional(comp.speed, node, "speed");
  if (const auto activeNode = node.find("active"); activeNode != node.cend()) {
    if (activeNode->get<bool>()) {
      comp.state = Activation::State::ACTIVE;
      comp.activity = 1.0f;
    }
  }
}
