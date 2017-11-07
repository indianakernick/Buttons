//
//  physics body component.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef physics_body_component_hpp
#define physics_body_component_hpp

#include "../Libraries/Box2D/Dynamics/b2Body.h"

struct PhysicsBody {
  b2Body *body = nullptr;
};

#endif
