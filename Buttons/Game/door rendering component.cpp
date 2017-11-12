//
//  door rendering component.cpp
//  Buttons
//
//  Created by Indi Kernick on 12/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "door rendering component.hpp"

#include "yaml helper.hpp"

DoorRendering::DoorRendering(const YAML::Node &node, const EntityIDmap &)
  : closeDir(Math::toDir(getChild(node, "close dir").Scalar())) {}
