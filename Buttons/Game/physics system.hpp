//
//  physics system.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef physics_system_hpp
#define physics_system_hpp

#include <experimental/optional>
#include <entt/entity/registry.hpp>
#include "physics body component.hpp"
#include "../Libraries/Box2D/Box2D.h"

class PhysicsSystem {
public:
  PhysicsSystem() = default;

  void init();
  void quit();
  
  void update(float);
  void iterate(entt::DefaultRegistry &);

private:
  std::experimental::optional<b2World> world;
};

#endif
