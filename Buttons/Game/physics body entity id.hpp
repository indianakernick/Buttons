//
//  physics body entity id.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef physics_body_entity_id_hpp
#define physics_body_entity_id_hpp

#include "entity constants.hpp"

inline void *getUserData(const EntityID entity) {
  return reinterpret_cast<void *>(
    static_cast<uintptr_t>(entity)
  );
}

inline EntityID getEntity(const void *const userData) {
  return static_cast<EntityID>(
    reinterpret_cast<uintptr_t>(userData)
  );
}

#endif
