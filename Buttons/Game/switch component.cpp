//
//  switch component.cpp
//  Buttons
//
//  Created by Indi Kernick on 12/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "switch component.hpp"

#include "yaml helper.hpp"
#include "entity id map.hpp"

Switch::Switch(const YAML::Node &node, const EntityIDmap &idMap)
  : player(idMap.getEntityFromUserID(getChild(node, "player").as<UserID>())) {}
