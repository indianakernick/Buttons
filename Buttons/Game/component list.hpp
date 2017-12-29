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
#include "text rendering component.hpp"
#include "moving platform component.hpp"
#include <Simpleton/Utils/type list.hpp>
#include "laser rendering component.hpp"
#include "anim sprite rendering component.hpp"
#include "static sprite rendering component.hpp"

#define COMPS                                                                   \
  COMP(PowerInput)                                                              \
  COMP(PowerOutput)                                                             \
  COMP(PhysicsBody)                                                             \
  COMP(PhysicsJoint)                                                            \
  COMP(PhysicsRayCast)                                                          \
  COMP(Transform)                                                               \
  COMP(Collision)                                                               \
  COMP(Activation)                                                              \
  COMP(PlayerInput)                                                             \
  COMP(PlayerJump)                                                              \
  COMP(Button)                                                                  \
  COMP(Door)                                                                    \
  COMP(Switch)                                                                  \
  COMP(Animation)                                                               \
  COMP(Exit)                                                                    \
  COMP(LaserDetector)                                                           \
  COMP(Text)                                                                    \
  COMP(Key)                                                                     \
  COMP(Lock)                                                                    \
  COMP(PlayerKeys)                                                              \
  COMP(StaticSpriteRendering)                                                   \
  COMP(AnimSpriteRendering)                                                     \
  COMP(LaserRendering)                                                          \
  COMP(TextRendering)                                                           \
  LAST_COMP(MovingPlatform)

#define COMP(NAME) NAME,
#define LAST_COMP(NAME) NAME
using CompList = Utils::TypeList<
  COMPS
>;
#undef LAST_COMP
#undef COMP

#undef COMPS

#endif
