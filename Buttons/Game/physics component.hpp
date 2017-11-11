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
#include "entity registry.hpp"
#include "../Libraries/Box2D/Dynamics/b2Body.h"
#include "../Libraries/Box2D/Dynamics/Joints/b2Joint.h"

namespace YAML {
  class Node;
}
class EntityIDmap;

struct PhysicsBody {
  //@TODO too many parameters
  PhysicsBody(const YAML::Node &, const EntityIDmap &, b2World &, EntityID);
  PhysicsBody(PhysicsBody &&);
  PhysicsBody &operator=(PhysicsBody &&);
  ~PhysicsBody();
  
  b2Body *body = nullptr;
  glm::vec2 scale;
};

struct PhysicsJoint {
  //@TODO too many parameters
  PhysicsJoint(const YAML::Node &, const EntityIDmap &, b2World &, EntityID, Registry &);

  b2Joint *joint = nullptr;
};

#endif
