//
//  physics body entity id.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef physics_body_entity_id_hpp
#define physics_body_entity_id_hpp

#include <Simpleton/ECS/registry.hpp>

inline void *getUserData(const ECS::EntityID entity) {
  return reinterpret_cast<void *>(
    static_cast<uintptr_t>(entity)
  );
}

inline ECS::EntityID getEntity(const void *const userData) {
  return static_cast<ECS::EntityID>(
    reinterpret_cast<uintptr_t>(userData)
  );
}

#endif
