//
//  exit system.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "exit system.hpp"

#include "exit component.hpp"
#include "collision component.hpp"

bool exitSystem(ECS::Registry &registry) {
  const auto view = registry.view<Exit, Collision>();
  for (const ECS::EntityID entity : view) {
    const CollisionPairs &pairs = view.get<Collision>(entity).collisionPairs;
    if (pairs.hasPair<B2::ObjT::Sensor, B2::ObjT::PlayerBody>()) {
      return true;
    }
  }
  return false;
}
