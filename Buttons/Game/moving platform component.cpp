//
//  moving platform component.cpp
//  Buttons
//
//  Created by Indi Kernick on 16/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "moving platform component.hpp"

#include "yaml helper.hpp"

MovingPlatform::MovingPlatform(const YAML::Node &node, const EntityIDmap &)
  : start(getChild(node, "start").as<b2Vec2>()),
    end(getChild(node, "end").as<b2Vec2>()) {
  getOptional(waitingTime, node, "waiting time");
  getOptional(moveSpeed, node, "speed");
}
