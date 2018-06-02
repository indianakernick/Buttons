//
//  physics body component.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef physics_body_component_hpp
#define physics_body_component_hpp

#include <glm/vec2.hpp>
#include <Simpleton/ECS/registry.hpp>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/Joints/b2Joint.h>

struct PhysicsBody {
  PhysicsBody() = default;
  PhysicsBody(PhysicsBody &&);
  PhysicsBody &operator=(PhysicsBody &&);
  ~PhysicsBody();
  
  // EnTT clone function
  PhysicsBody(const PhysicsBody &) {}
  PhysicsBody &operator=(const PhysicsBody &) {
    return *this;
  }
  
  b2Body *body = nullptr;
  glm::vec2 scale;
};

struct PhysicsJoint {
  b2Joint *joint = nullptr;
};

struct PhysicsRayCast {
  //The ray cast is only used for the laser sensor so there is no need to
  //clutter this struct with data for other types of raycasts.
  b2Vec2 start;
  b2Vec2 end;
  float32 closestFraction = 1.0f;
};

#endif
