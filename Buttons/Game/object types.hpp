//
//  object types.hpp
//  Buttons
//
//  Created by Indi Kernick on 8/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef object_types_hpp
#define object_types_hpp

#define OBJECT_TYPES                                                            \
  OBJECT_TYPE(PlayerBody)                                                       \
  OBJECT_TYPE(PlayerFoot)                                                       \
  OBJECT_TYPE(Ground)                                                           \
  OBJECT_TYPE(Sensor)                                                           \
  LAST_OBJECT_TYPE(Button)

#include <Simpleton/Box2D/object types.hpp>

#undef OBJECT_TYPES

#endif
