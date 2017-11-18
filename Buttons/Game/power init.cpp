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
  comp.in = idMap.getEntityFromUserID(getChild(node, "in").as<UserID>());
}
