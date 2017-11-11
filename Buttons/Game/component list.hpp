//
//  component list.hpp
//  Buttons
//
//  Created by Indi Kernick on 11/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef component_list_hpp
#define component_list_hpp

#include "power component.hpp"
#include "physics component.hpp"
#include "transform component.hpp"
#include "collision component.hpp"
#include "activation component.hpp"
#include "player jump component.hpp"
#include "player input component.hpp"
#include "box rendering component.hpp"
#include <Simpleton/Utils/type list.hpp>
#include "player rendering component.hpp"

using CompList = Utils::TypeList<
  PowerInput,
  PowerOutput,
  PhysicsBody,
  PhysicsJoint,
  Transform,
  Collision,
  Activation,
  BoxRendering,
  PlayerInput,
  PlayerJump,
  PlayerRendering
>;

#endif
