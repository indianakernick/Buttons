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
#include "contact listener.hpp"
#include <experimental/optional>
#include "collision component.hpp"
#include <Box2D/Box2D.h>
#include <Simpleton/ECS/registry.hpp>

class PhysicsSystem {
public:
  PhysicsSystem() = default;

  void init(ECS::Registry &);
  void quit();
  
  b2World *getWorld();
  
  void update(float);
  void render();

private:
  ECS::Registry *registry = nullptr;
  std::experimental::optional<b2World> world;
  std::experimental::optional<ContactListener> contactListener;
  std::experimental::optional<DebugDraw> debugDraw;
  
  void beginContact(CollisionPair);
  void endContact(CollisionPair);
};

#endif
