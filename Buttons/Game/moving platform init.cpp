//
//  moving platform init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "moving platform init.hpp"

#include <Simpleton/Box2D/json.hpp>

void MovingPlatformInit::init(MovingPlatform &comp, const json &node) {
  comp.start = node.at("start").get<b2Vec2>();
  comp.end = node.at("end").get<b2Vec2>();
  Data::getOptional(comp.waitingTime, node, "waiting time");
  Data::getOptional(comp.moveSpeed, node, "speed");
  
  if (const auto piston = node.find("piston"); piston != node.cend()) {
    if (piston->get<bool>()) {
      //piston mode overrides "waiting time"
      comp.waitingTime = MovingPlatform::PISTON;
    }
  }
}
