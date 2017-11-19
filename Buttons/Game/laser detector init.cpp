//
//  laser detector init.cpp
//  Buttons
//
//  Created by Indi Kernick on 19/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "laser detector init.hpp"

#include "yaml helper.hpp"
#include "entity id map.hpp"

void LaserDetectorInit::init(LaserDetector &comp, const YAML::Node &node, const EntityIDmap &idMap) {
  comp.emitter = idMap.getEntityFromUserID(getChild(node, "emitter").as<UserID>());
}
