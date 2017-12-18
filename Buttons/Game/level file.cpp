//
//  level file.cpp
//  Buttons
//
//  Created by Indi Kernick on 2/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "level file.hpp"

#include <fstream>
#include "comp inits.hpp"
#include "json helper.hpp"
#include "entity id map.hpp"
#include <Simpleton/Platform/system info.hpp>

namespace {
  void loadComps(
    const EntityID id,
    const json &comps,
    const EntityIDmap &idMap,
    const CompInits &compInits,
    Registry &registry
  ) {
    auto obj = comps.get_ref<const json::object_t &>();
    for (auto &pair : obj) {
      const bool gotComp = Utils::getByName<CompList>(
        pair.first,
        [id, &idMap, &registry, &compInits, &props = pair.second] (auto t) {
          compInits.init(registry.accomodate<UTILS_TYPE(t)>(id), props, idMap, id);
        }
      );
      if (!gotComp) {
        /*throw std::runtime_error(
          "Unknown component name \""
          + pair.first
          + "\""
        );*/
      }
    }
  }
}

bool loadLevel(const std::string &fileName, const CompInits &compInits, Registry &registry) {
  std::ifstream file(Platform::getResDir() + fileName);
  if (!file.is_open()) {
    return false;
  }
  json root;
  file >> root;
  
  EntityIDmap idMap;
  idMap.insertIDs(root, registry);
  
  for (size_t i = 0; i != root.size(); ++i) {
    const EntityID id = idMap.getEntityFromIndex(i);
    const json &node = root[i];
    
    if (const auto compsNode = node.find("components"); compsNode != node.cend()) {
      loadComps(id, *compsNode, idMap, compInits, registry);
    }
  }
  
  return true;
}
