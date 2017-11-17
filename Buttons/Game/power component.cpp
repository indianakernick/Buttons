//
//  power component.cpp
//  Buttons
//
//  Created by Indi Kernick on 9/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "power component.hpp"

#include "yaml helper.hpp"
#include "entity id map.hpp"

PowerInput::PowerInput(const YAML::Node &node, const EntityIDmap &idMap) {
  in = idMap.getEntityFromUserID(getChild(node, "in").as<UserID>());
}
