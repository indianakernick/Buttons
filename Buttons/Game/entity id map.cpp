//
//  entity id map.cpp
//  Buttons
//
//  Created by Indi Kernick on 10/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "entity id map.hpp"

#include <cassert>

void EntityIDmap::insertIDs(const json &root, ECS::Registry &registry) {
  assert(map.empty());
  map.resize(root.size());
  
  for (size_t i = 0; i != map.size(); ++i) {
    const json &node = root[i];
    ClientEntityID clientID = NULL_CLIENT_ENTITY_ID;
    if (const auto idNode = node.find("id"); idNode != node.cend()) {
      clientID = idNode->get<ClientEntityID>();
      if (clientID == NULL_CLIENT_ENTITY_ID) {
        throw std::runtime_error("Usage of reserved user defined entity ID");
      }
      for (size_t j = 0; j != i; ++j) {
        if (map[j].first == clientID) {
          throw std::runtime_error("All user defined entity IDs must be unique or absent");
        }
      }
    }
    map[i] = {clientID, registry.create()};
  }
}

ECS::EntityID EntityIDmap::getEntityFromIndex(const size_t i) const {
  if (i < map.size()) {
    return map[i].second;
  }
  throw std::runtime_error("Invalid index");
}

ECS::EntityID EntityIDmap::getEntityFromID(const ClientEntityID id) const {
  for (auto &pair : map) {
    if (pair.first == id) {
      return pair.second;
    }
  }
  throw std::runtime_error("Invalid user ID");
}
