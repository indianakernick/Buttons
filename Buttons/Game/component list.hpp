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
#include "box rendering component.hpp"
#include "key rendering component.hpp"
#include "lock rendering component.hpp"
#include "text rendering component.hpp"
#include "door rendering component.hpp"
#include "exit rendering component.hpp"
#include "laser detector component.hpp"
#include "moving platform component.hpp"
#include <Simpleton/Utils/type list.hpp>
#include "shadow rendering component.hpp"
#include "switch rendering component.hpp"
#include "button rendering component.hpp"
#include "player rendering component.hpp"
#include "platform rendering component.hpp"
#include "laser emitter rendering component.hpp"
#include "laser detector rendering component.hpp"
#include "moving platform rendering component.hpp"

#define COMPS                                                                   \
  COMP(PowerInput, powerInput)                                                  \
  COMP(MultiPowerInput, multiPowerInput)                                        \
  COMP(PowerOutput, powerOutput)                                                \
  COMP(PhysicsBody, physicsBody)                                                \
  COMP(PhysicsJoint, physicsJoint)                                              \
  COMP(PhysicsRayCast, physicsRayCast)                                          \
  COMP(Transform, transform)                                                    \
  COMP(Collision, collision)                                                    \
  COMP(Activation, activation)                                                  \
  COMP(BoxRendering, boxRendering)                                              \
  COMP(PlayerInput, playerInput)                                                \
  COMP(PlayerJump, playerJump)                                                  \
  COMP(PlayerRendering, playerRendering)                                        \
  COMP(PlatformRendering, platformRendering)                                    \
  COMP(Button, button)                                                          \
  COMP(ButtonRendering, buttonRendering)                                        \
  COMP(DoorRendering, doorRendering)                                            \
  COMP(Door, door)                                                              \
  COMP(Switch, switch)                                                          \
  COMP(SwitchRendering, switchRendering)                                        \
  COMP(Animation, animation)                                                    \
  COMP(ExitRendering, exitRendering)                                            \
  COMP(Exit, exit)                                                              \
  COMP(LaserDetector, laserDetector)                                            \
  COMP(LaserEmitterRendering, laserEmitterRendering)                            \
  COMP(LaserDetectorRendering, laserDetectorRendering)                          \
  COMP(TextRendering, textRendering)                                            \
  COMP(Text, text)                                                              \
  COMP(Key, key)                                                                \
  COMP(Lock, lock)                                                              \
  COMP(PlayerKeys, playerKeys)                                                  \
  COMP(KeyRendering, keyRendering)                                              \
  COMP(ShadowRendering, shadowRendering)                                        \
  COMP(LockRendering, lockRendering)                                            \
  COMP(MovingPlatformRendering, movingPlatformRendering)                        \
  LAST_COMP(MovingPlatform, movingPlatform)

#define COMP(NAME, ID_NAME) NAME,
#define LAST_COMP(NAME, ID_NAME) NAME
using CompList = Utils::TypeList<
  COMPS
>;
#undef LAST_COMP
#undef COMP

#endif
