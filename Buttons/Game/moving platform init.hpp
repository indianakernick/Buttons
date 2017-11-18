//
//  moving platform init.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef moving_platform_init_hpp
#define moving_platform_init_hpp

#include "comp init.hpp"
#include "moving platform component.hpp"

class MovingPlatformInit : CompInit<MovingPlatform> {
public:
  void init(MovingPlatform &, const YAML::Node &, const EntityIDmap &, EntityID);
};

#endif
