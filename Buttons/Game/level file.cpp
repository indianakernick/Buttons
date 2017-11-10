//
//  level file.cpp
//  Buttons
//
//  Created by Indi Kernick on 10/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "level file.hpp"

#include <unordered_map>
#include "yaml helper.hpp"
#include <Simpleton/Platform/system info.hpp>

namespace {
  using UserID = int;
  constexpr UserID MIN_USER_ID = std::numeric_limits<UserID>::min();
  constexpr UserID MAX_USER_ID = std::numeric_limits<UserID>::max();
}

void loadLevel(const std::string &fileName, Registry &registry) {
  const YAML::Node root = YAML::LoadFile(Platform::getResDir() + fileName);
  checkType(root, YAML::NodeType::Sequence);
  //Mapping from IDs that the users will use to IDs that the game will use
  std::unordered_map<UserID, EntityID> idMap;
  
  UserID minUserID = MAX_USER_ID;
  UserID maxUserID = MIN_USER_ID;
  for (auto n = root.begin(); n != root.end(); ++n) {
    if (const YAML::Node &idNode = (*n)["id"]) {
      const UserID userID = idNode.as<UserID>();
      minUserID = std::min(minUserID, userID);
      maxUserID = std::max(maxUserID, userID);
      if (!idMap.emplace(userID, registry.create()).second) {
        throw std::runtime_error("All entity IDs must be unique or absent");
      }
    }
  }
  
  const UserID absentUserIDs = static_cast<UserID>(root.size() - idMap.size());
  const UserID lowerFreeUserIDs = minUserID - MIN_USER_ID;
  const UserID upperFreeUserIDs = MAX_USER_ID - maxUserID;
  
  if (absentUserIDs < lowerFreeUserIDs) {
    const UserID lastUserID = minUserID - absentUserIDs;
    for (UserID id = minUserID - 1; id >= lastUserID; --id) {
      idMap.emplace(id, registry.create());
    }
  } else if (absentUserIDs < upperFreeUserIDs) {
    const UserID lastUserID = maxUserID + absentUserIDs;
    for (UserID id = maxUserID + 1; id <= lastUserID; ++id) {
      idMap.emplace(id, registry.create());
    }
  } else if (absentUserIDs) {
    for (UserID id = MIN_USER_ID; true; ++id) {
      const bool inserted = idMap.emplace(id, registry.create()).second;
      if (inserted && root.size() == idMap.size()) {
        break;
      }
      if (id == MAX_USER_ID) {
        throw std::runtime_error("Too many entities");
      }
    }
  }
  
  
}
