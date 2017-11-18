//
//  switch init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "switch init.hpp"

#include "yaml helper.hpp"
#include "entity id map.hpp"

void SwitchInit::init(Switch &comp, const YAML::Node &node, const EntityIDmap &idMap) {
  comp.player = idMap.getEntityFromUserID(getChild(node, "player").as<UserID>());
}
