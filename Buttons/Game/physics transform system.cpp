//
//  physics transform system.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "physics transform system.hpp"

#include "b2 glm cast.hpp"
#include "physics component.hpp"
#include "transform component.hpp"

void physicsTransformSystem(Registry &registry) {
  auto view = registry.view<PhysicsBody, Transform>();
  for (EntityID entity : view) {
    const PhysicsBody &physics = view.get<PhysicsBody>(entity);
    b2Body *const body = physics.body;
    Transform &transform = view.get<Transform>(entity);
    transform.pos = castToGLM(body->GetPosition());
    transform.scale = physics.scale;
    transform.rotation = body->GetAngle();
  }
}
