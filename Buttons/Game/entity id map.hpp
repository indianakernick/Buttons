//
//  entity id map.hpp
//  Buttons
//
//  Created by Indi Kernick on 10/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef entity_id_map_hpp
#define entity_id_map_hpp

#include <vector>
#include <Simpleton/Data/json.hpp>
#include <Simpleton/ECS/registry.hpp>

using ClientEntityID = int;
constexpr ClientEntityID NULL_CLIENT_ENTITY_ID = std::numeric_limits<ClientEntityID>::min();

class EntityIDmap {
public:
  EntityIDmap() = default;
  
  void insertIDs(const json &, ECS::Registry &);
  ECS::EntityID getEntityFromID(ClientEntityID) const;
  ECS::EntityID getEntityFromIndex(size_t) const;

private:
  std::vector<std::pair<ClientEntityID, ECS::EntityID>> map;
};

#endif
