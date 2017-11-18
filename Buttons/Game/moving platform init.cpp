//
//  moving platform init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "moving platform init.hpp"

#include "yaml helper.hpp"

void MovingPlatformInit::init(MovingPlatform &comp, const YAML::Node &node) {
  comp.start = getChild(node, "start").as<b2Vec2>();
  comp.end = getChild(node, "end").as<b2Vec2>();
  getOptional(comp.waitingTime, node, "waiting time");
  getOptional(comp.moveSpeed, node, "speed");
}
