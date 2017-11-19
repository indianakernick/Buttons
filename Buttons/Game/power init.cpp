//
//  power init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "power init.hpp"

#include "yaml helper.hpp"
#include "entity id map.hpp"

void PowerInputInit::init(PowerInput &comp, const YAML::Node &node, const EntityIDmap &idMap) {
  if (const YAML::Node &inNode = node["in"]) {
    comp.in = idMap.getEntityFromUserID(inNode.as<UserID>());
  } else {
    comp.in = NULL_ENTITY;
  }
  getOptional(comp.on, node, "on");
}
