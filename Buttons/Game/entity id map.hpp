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
#include "json helper.hpp"
#include "entity registry.hpp"

using UserID = int;
constexpr UserID NULL_USER_ID = std::numeric_limits<UserID>::min();

class EntityIDmap {
public:
  EntityIDmap() = default;
  
  void insertIDs(const json &, Registry &);
  EntityID getEntityFromUserID(UserID) const;
  EntityID getEntityFromIndex(size_t) const;

private:
  std::vector<std::pair<UserID, EntityID>> map;
};

#endif
