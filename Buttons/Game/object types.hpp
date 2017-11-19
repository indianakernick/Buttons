//
//  object types.hpp
//  Buttons
//
//  Created by Indi Kernick on 8/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef object_types_hpp
#define object_types_hpp

#include <utility>
#include <Simpleton/Utils/type list.hpp>
#include <Simpleton/Utils/instance limiter.hpp>

using ObjectTypeID = uint32_t;
using CollisionPair = std::pair<ObjectTypeID, ObjectTypeID>;

template <typename ObjectType>
ObjectTypeID getObjectTypeID() {
  return static_cast<ObjectTypeID>(Utils::typeHash<ObjectType>());
}

template <typename ObjectType>
void *getUserData() {
  return reinterpret_cast<void *>(
    static_cast<uintptr_t>(getObjectTypeID<ObjectType>())
  );
}

inline ObjectTypeID getObjectTypeID(const void *const userData) {
  return static_cast<ObjectTypeID>(
    reinterpret_cast<uintptr_t>(userData)
  );
}

#define OBJECT_TYPES                                                            \
  OBJECT_TYPE(PlayerBody)                                                       \
  OBJECT_TYPE(PlayerFoot)                                                       \
  OBJECT_TYPE(Ground)                                                           \
  OBJECT_TYPE(Sensor)                                                           \
  LAST_OBJECT_TYPE(Button)

namespace ObjectType {
  #define OBJECT_TYPE(NAME) MAKE_SYMBOL(NAME);
  #define LAST_OBJECT_TYPE(NAME) OBJECT_TYPE(NAME)
  OBJECT_TYPES
  #undef LAST_OBJECT_TYPE
  #undef OBJECT_TYPE
};

using ObjectTypes = Utils::TypeList<
  #define OBJECT_TYPE(NAME) ObjectType::NAME,
  #define LAST_OBJECT_TYPE(NAME) ObjectType::NAME
  OBJECT_TYPES
  #undef LAST_OBJECT_TYPE
  #undef OBJECT_TYPE
>;

#undef OBJECT_TYPES

void *getUserData(const std::string &);

#endif
