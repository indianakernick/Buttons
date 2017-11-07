//
//  power component.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef power_component_hpp
#define power_component_hpp

#include <limits>
#include "entity constants.hpp"

struct PowerInput {
  bool on = false;
};

struct PowerOutput {
  bool on = false;
  EntityID out = std::numeric_limits<EntityID>::max();
};

#endif
