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
#include "../Libraries/Box2D/Dynamics/b2World.h"
#include "../Libraries/Box2D/Dynamics/Joints/b2Joint.h"

struct PhysicsBody {
  ~PhysicsBody() {
    if (body) {
      b2World *const world = body->GetWorld();
      if (world) {
        world->DestroyBody(body);
      }
    }
  }

  b2Body *body = nullptr;
};

struct PhysicsJoint {
  b2Joint *joint = nullptr;
};

#endif
