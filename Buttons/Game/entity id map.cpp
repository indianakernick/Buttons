//
//  entity id map.cpp
//  Buttons
//
//  Created by Indi Kernick on 10/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "entity id map.hpp"

#include <cassert>

void EntityIDmap::insertIDs(const YAML::Node &root, Registry &registry) {
  assert(map.empty());
  
  map.resize(root.size());
  for (size_t i = 0; i != map.size(); ++i) {
    const YAML::Node &node = root[i];
    UserID userID = NULL_USER_ID;
    if (const YAML::Node &idNode = (node)["id"]) {
      userID = idNode.as<UserID>();
      if (userID == NULL_USER_ID) {
        throw std::runtime_error("Usage of reserved user defined entity ID");
      }
      for (size_t j = 0; j != i; ++j) {
        if (map[j].first == userID) {
          throw std::runtime_error("All user defined entity IDs must be unique or absent");
        }
      }
    }
    map[i] = {userID, registry.create()};
  }
}

void EntityIDmap::insertIDs(const json &root, Registry &registry) {
  assert(map.empty());
  map.resize(root.size());
  
  for (size_t i = 0; i != map.size(); ++i) {
    const json &node = root[i];
    UserID userID = NULL_USER_ID;
    if (const auto idNode = node.find("id"); idNode != node.cend()) {
      userID = idNode->get<UserID>();
      if (userID == NULL_USER_ID) {
        throw std::runtime_error("Usage of reserved user defined entity ID");
      }
      for (size_t j = 0; j != i; ++j) {
        if (map[j].first == userID) {
          throw std::runtime_error("All user defined entity IDs must be unique or absent");
        }
      }
      map[i] = {userID, registry.create()};
    }
  }
}

EntityID EntityIDmap::getEntityFromIndex(const size_t i) const {
  if (i < map.size()) {
    return map[i].second;
  }
  throw std::runtime_error("Invalid index");
}

EntityID EntityIDmap::getEntityFromUserID(const UserID id) const {
  for (auto &pair : map) {
    if (pair.first == id) {
      return pair.second;
    }
  }
  throw std::runtime_error("Invalid user ID");
}
