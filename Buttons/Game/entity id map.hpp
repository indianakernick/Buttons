//
//  entity id map.hpp
//  Buttons
//
//  Created by Indi Kernick on 10/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef entity_id_map_hpp
#define entity_id_map_hpp

#include <unordered_map>
#include <yaml-cpp/yaml.h>
#include "entity registry.hpp"

using UserID = int;

class EntityIDmap {
public:
  EntityIDmap() = default;
  
  void insertIDs(const YAML::Node &, Registry &);
  EntityID getEntityID(UserID) const;

private:
  static constexpr UserID MIN_USER_ID = std::numeric_limits<UserID>::min();
  static constexpr UserID MAX_USER_ID = std::numeric_limits<UserID>::max();

  std::unordered_map<UserID, EntityID> map;
  UserID minUserID = MAX_USER_ID;
  UserID maxUserID = MIN_USER_ID;
  bool insertedIDs = false;
  
  void insertDefinedIDs(const YAML::Node &, Registry &);
  void insertAbsentIDs(const YAML::Node &, Registry &);
  void genAbsentIDsLow(UserID, Registry &);
  void genAbsentIDsHigh(UserID, Registry &);
  void genAbsentIDsBrute(UserID, Registry &);
};

#endif
