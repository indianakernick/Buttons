//
//  physics constants.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef physics_constants_hpp
#define physics_constants_hpp

#include "../Libraries/Box2D/Common/b2Math.h"

const b2Vec2 GRAVITY = {0.0f, -9.80665f};
constexpr int32 VELOCITY_ITER = 16;
constexpr int32 POSITION_ITER = 8;

#endif
