//
//  moving platform init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "moving platform init.hpp"

namespace {
  float getWaitingTime(const json &waitNode) {
    if (waitNode.is_number()) {
      if (const float time = waitNode.get<float>(); time >= 0.0f) {
        return time;
      }
    } else if (waitNode.is_string()) {
      if (waitNode.get_ref<const std::string &>() == "piston") {
        return MovingPlatform::PISTON;
      }
    }
    throw std::runtime_error(
      "Invalid value for \"waiting time\": "
      + waitNode.dump()
    );
  }
}

void MovingPlatformInit::init(MovingPlatform &comp, const json &node) {
  comp.start = node.at("start").get<b2Vec2>();
  comp.end = node.at("end").get<b2Vec2>();
  if (const auto waitNode = node.find("waiting time"); waitNode != node.cend()) {
    comp.waitingTime = getWaitingTime(*waitNode);
  }
  getOptional(comp.moveSpeed, node, "speed");
}
