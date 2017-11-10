//
//  entity id map.cpp
//  Buttons
//
//  Created by Indi Kernick on 10/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "entity id map.hpp"

#include <cassert>
#include <Simpleton/Utils/bits.hpp>

void EntityIDmap::insertIDs(const YAML::Node &root, Registry &registry) {
  assert(!insertedIDs);
  insertedIDs = true;
  insertDefinedIDs(root, registry);
  insertAbsentIDs(root, registry);
}

EntityID EntityIDmap::getEntityID(const UserID id) const {
  auto iter = map.find(id);
  if (iter == map.cend()) {
    throw std::runtime_error("Invalid user ID");
  } else {
    return iter->second;
  }
}

void EntityIDmap::insertDefinedIDs(const YAML::Node &root, Registry &registry) {
  for (auto n = root.begin(); n != root.end(); ++n) {
    if (const YAML::Node &idNode = (*n)["id"]) {
      const UserID userID = idNode.as<UserID>();
      minUserID = std::min(minUserID, userID);
      maxUserID = std::max(maxUserID, userID);
      if (!map.emplace(userID, registry.create()).second) {
        throw std::runtime_error("All entity IDs must be unique or absent");
      }
    }
  }
}

void EntityIDmap::insertAbsentIDs(const YAML::Node &root, Registry &registry) {
  const UserID absentUserIDs = static_cast<UserID>(root.size() - map.size());
  if (absentUserIDs) {
    const UserID lowerFreeUserIDs = minUserID - MIN_USER_ID;
    const UserID upperFreeUserIDs = MAX_USER_ID - maxUserID;

    if (absentUserIDs < lowerFreeUserIDs) {
      genAbsentIDsLow(absentUserIDs, registry);
    } else if (absentUserIDs < upperFreeUserIDs) {
      genAbsentIDsHigh(absentUserIDs, registry);
    } else {
      genAbsentIDsBrute(absentUserIDs, registry);
    }
  }
}

void EntityIDmap::genAbsentIDsLow(const UserID absentUserIDs, Registry &registry) {
  const UserID lastUserID = minUserID - absentUserIDs;
  for (UserID id = minUserID - 1; id >= lastUserID; --id) {
    map.emplace(minUserID, registry.create());
  }
}

void EntityIDmap::genAbsentIDsHigh(const UserID absentUserIDs, Registry &registry) {
  const UserID lastUserID = maxUserID + absentUserIDs;
  for (UserID id = maxUserID + 1; id <= lastUserID; ++id) {
    map.emplace(id, registry.create());
  }
}

namespace {
  constexpr size_t maxUserIDs() {
    static_assert(std::is_integral_v<UserID>);
    if constexpr (std::is_signed_v<UserID>) {
      return (size_t(1) << Utils::bits<UserID>) - 1;
    } else {
      return std::numeric_limits<UserID>::max();
    }
  }
}

void EntityIDmap::genAbsentIDsBrute(const UserID absentUserIDs, Registry &registry) {
  const size_t totalIDs = static_cast<size_t>(absentUserIDs) + map.size();
  const size_t maxIDs = maxUserIDs();
  if (totalIDs > maxIDs) {
    throw std::runtime_error("Too many entities");
  }
  
  UserID numInserted = 0;
  for (UserID id = 0; numInserted != absentUserIDs; ++id) {
    numInserted += map.emplace(id, registry.create()).second;
  }
}
