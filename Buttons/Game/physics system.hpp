//
//  physics system.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef physics_system_hpp
#define physics_system_hpp

#include "debug draw.hpp"
#include "entity registry.hpp"
#include "contact listener.hpp"
#include <experimental/optional>
#include "collision component.hpp"
#include "../Libraries/Box2D/Box2D.h"

class PhysicsSystem {
public:
  PhysicsSystem() = default;

  void init(Registry &, NVGcontext *);
  void quit();
  
  b2World *getWorld();
  
  void update(float);
  void render();

private:
  entt::Registry<EntityID> *registry = nullptr;
  std::experimental::optional<b2World> world;
  std::experimental::optional<ContactListener> contactListener;
  std::experimental::optional<DebugDraw> debugDraw;
  
  void beginContact(CollisionPair);
  void endContact(CollisionPair);
};

#endif
