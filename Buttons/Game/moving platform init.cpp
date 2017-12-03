//
//  moving platform init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "moving platform init.hpp"

void MovingPlatformInit::init(MovingPlatform &comp, const json &node) {
  comp.start = node.at("start").get<b2Vec2>();
  comp.end = node.at("end").get<b2Vec2>();
  if (const auto waitNode = node.find("waiting time"); waitNode != node.cend()) {
    if (waitNode->is_number()) {
      comp.waitingTime = waitNode->get<float>();
    } else if (waitNode->is_string()) {
      if (waitNode->get_ref<const std::string &>() == "forever") {
        comp.waitingTime = std::numeric_limits<float>::max();
      } else {
        throw std::runtime_error(
          "Invalid value for \"waiting time\": "
          + waitNode->dump()
        );
      }
    }
  }
  getOptional(comp.moveSpeed, node, "speed");
}
