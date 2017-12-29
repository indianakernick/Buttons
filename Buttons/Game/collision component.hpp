//
//  collision component.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef collision_component_hpp
#define collision_component_hpp

#include "object types.hpp"
#include <Simpleton/Box2D/collision pairs.hpp>

struct Collision {
  B2::CollisionPairs collisionPairs;
};

#endif
