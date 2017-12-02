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
  getOptional(comp.waitingTime, node, "waiting time");
  getOptional(comp.moveSpeed, node, "speed");
}
