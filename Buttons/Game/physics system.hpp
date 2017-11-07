//
//  physics system.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef physics_system_hpp
#define physics_system_hpp

#include "entity constants.hpp"
#include "contact listener.hpp"
#include <experimental/optional>
#include "collision component.hpp"
#include <entt/entity/registry.hpp>
#include "physics body component.hpp"
#include "../Libraries/Box2D/Box2D.h"

class PhysicsSystem {
public:
  PhysicsSystem() = default;

  void init(entt::Registry<EntityID> &);
  void quit();
  
  void update(float);

private:
  entt::Registry<EntityID> *registry = nullptr;
  std::experimental::optional<b2World> world;
  std::experimental::optional<ContactListener> contactListener;
  
  void beginContact(EntityID, EntityID, uint16_t, uint16_t);
  void endContact(EntityID, EntityID, uint16_t, uint16_t);
};

#endif
