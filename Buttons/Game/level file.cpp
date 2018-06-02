//
//  level file.cpp
//  Buttons
//
//  Created by Indi Kernick on 2/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "level file.hpp"

#include <fstream>
#include <Simpleton/ECS/json.hpp>
#include <Simpleton/SDL/paths.hpp>
#include <Simpleton/Type List/get.hpp>
#include <Simpleton/ECS/entity id map.hpp>

namespace {
  void loadComps(
    const ECS::EntityID id,
    const json &comps,
    const ECS::EntityIDmap &idMap,
    const ECS::CompInits<CompList> &compInits,
    ECS::Registry &registry
  ) {
    auto obj = comps.get_ref<const json::object_t &>();
    for (auto &pair : obj) {
      const bool gotComp = List::getByName<CompList>(
        pair.first,
        [id, &idMap, &registry, &compInits, &props = pair.second] (auto t) {
          compInits.init(registry.assign<LIST_TYPE(t)>(id), props, idMap, id);
        }
      );
      if (!gotComp) {
        throw std::runtime_error(
          "Unknown component name \""
          + pair.first
          + "\""
        );
      }
    }
  }
}

bool loadLevel(
  const std::string &fileName,
  const ECS::CompInits<CompList> &compInits,
  ECS::Registry &registry
) {
  std::ifstream file(SDL::getResDir() + fileName);
  if (!file.is_open()) {
    return false;
  }
  json root;
  file >> root;
  
  ECS::EntityIDmap idMap;
  ECS::insertPairs(idMap, root, registry);
  
  for (size_t i = 0; i != root.size(); ++i) {
    const ECS::EntityID id = idMap.getEntityFromIndex(i);
    const json &node = root[i];
    
    if (JSON_OPTIONAL(compsNode, node, "components")) {
      loadComps(id, *compsNode, idMap, compInits, registry);
    }
  }
  
  return true;
}
