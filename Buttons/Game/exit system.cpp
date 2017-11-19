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

bool exitSystem(Registry &registry) {
  const auto view = registry.view<Exit, Collision>();
  for (const EntityID entity : view) {
    const CollisionPairs &pairs = view.get<Collision>(entity).collisionPairs;
    if (pairs.hasPair<ObjectType::Sensor, ObjectType::PlayerBody>()) {
      return true;
    }
  }
  return false;
}
