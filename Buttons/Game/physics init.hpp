//
//  physics init.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef physics_init_hpp
#define physics_init_hpp

#include "comp init.hpp"
#include "physics component.hpp"

class PhysicsBodyInit : CompInit<PhysicsBody> {
public:
  explicit PhysicsBodyInit(b2World *);
  
  void init(PhysicsBody &, const YAML::Node &, const EntityIDmap &, EntityID);

private:
  b2World *world;
};

#endif
