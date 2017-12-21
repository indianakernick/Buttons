//
//  component list.hpp
//  Buttons
//
//  Created by Indi Kernick on 11/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef component_list_hpp
#define component_list_hpp

#include "key component.hpp"
#include "lock component.hpp"
#include "text component.hpp"
#include "exit component.hpp"
#include "door component.hpp"
#include "power component.hpp"
#include "switch component.hpp"
#include "button component.hpp"
#include "physics component.hpp"
#include "transform component.hpp"
#include "collision component.hpp"
#include "animation component.hpp"
#include "activation component.hpp"
#include "player keys component.hpp"
#include "player jump component.hpp"
#include "player input component.hpp"
#include "laser detector component.hpp"
#include "moving platform component.hpp"
#include <Simpleton/Utils/type list.hpp>
#include "anim sprite rendering component.hpp"
#include "active sprite rendering component.hpp"
#include "static sprite rendering component.hpp"

#define COMPS                                                                   \
  COMP(PowerInput, powerInput)                                                  \
  COMP(PowerOutput, powerOutput)                                                \
  COMP(PhysicsBody, physicsBody)                                                \
  COMP(PhysicsJoint, physicsJoint)                                              \
  COMP(PhysicsRayCast, physicsRayCast)                                          \
  COMP(Transform, transform)                                                    \
  COMP(Collision, collision)                                                    \
  COMP(Activation, activation)                                                  \
  COMP(PlayerInput, playerInput)                                                \
  COMP(PlayerJump, playerJump)                                                  \
  COMP(Button, button)                                                          \
  COMP(Door, door)                                                              \
  COMP(Switch, switch)                                                          \
  COMP(Animation, animation)                                                    \
  COMP(Exit, exit)                                                              \
  COMP(LaserDetector, laserDetector)                                            \
  COMP(Text, text)                                                              \
  COMP(Key, key)                                                                \
  COMP(Lock, lock)                                                              \
  COMP(PlayerKeys, playerKeys)                                                  \
  COMP(ActiveSpriteRendering, activeSpriteRendering)                            \
  COMP(StaticSpriteRendering, staticSpriteRendering)                            \
  COMP(AnimSpriteRendering, animSpriteRendering)                                \
  LAST_COMP(MovingPlatform, movingPlatform)

#define COMP(NAME, ID_NAME) NAME,
#define LAST_COMP(NAME, ID_NAME) NAME
using CompList = Utils::TypeList<
  COMPS
>;
#undef LAST_COMP
#undef COMP

#endif
