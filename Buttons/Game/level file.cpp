//
//  level file.cpp
//  Buttons
//
//  Created by Indi Kernick on 10/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "level file.hpp"

#include <fstream>
#include "comp inits.hpp"
#include "yaml helper.hpp"
#include "entity id map.hpp"
#include "physics system.hpp"
#include <Simpleton/Platform/system info.hpp>

void loadComps(
  const EntityID id,
  const YAML::Node &comps,
  const EntityIDmap &idMap,
  Registry &registry,
  const CompInits &compInits
) {
  for (auto &pair : comps) {
    const std::string &compName = pair.first.Scalar();
    const YAML::Node &props = pair.second;
    Utils::getByName<CompList>(compName, [id, &idMap, &registry, &compInits, props] (auto t) {
      compInits.init(registry.accomodate<UTILS_TYPE(t)>(id), props, idMap, id);
    });
  }
}

void loadEntity(
  const EntityID id,
  const std::string &entityFileName,
  const YAML::Node &levelComps,
  const EntityIDmap &idMap,
  Registry &registry,
  const CompInits &compInits
) {
  const YAML::Node comps = YAML::LoadFile(Platform::getResDir() + entityFileName);
  checkType(comps, YAML::NodeType::Map);
  checkType(levelComps, YAML::NodeType::Map);
  loadComps(id, comps, idMap, registry, compInits);
  loadComps(id, levelComps, idMap, registry, compInits);
}

bool loadLevel(const std::string &fileName, Registry &registry, const CompInits &compInits) {
  std::ifstream file(Platform::getResDir() + fileName);
  if (!file.is_open()) {
    return false;
  }
  const YAML::Node root = YAML::Load(file);
  checkType(root, YAML::NodeType::Sequence);
  EntityIDmap idMap;
  idMap.insertIDs(root, registry);
  
  for (size_t i = 0; i != root.size(); ++i) {
    const YAML::Node &node = root[i];
    const std::string &entityFile = getChild(node, "file").Scalar();
    const YAML::Node &comps = node["components"];
    loadEntity(idMap.getEntityFromIndex(i), entityFile, comps, idMap, registry, compInits);
  }
  
  return true;
}
