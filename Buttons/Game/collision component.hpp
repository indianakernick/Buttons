//
//  collision component.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef collision_component_hpp
#define collision_component_hpp

#include <cstdint>

struct Collision {
  uint16_t category = 0;
  uint16_t collidingCategory = 0;
};

#endif
