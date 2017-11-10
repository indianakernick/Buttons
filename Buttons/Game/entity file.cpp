//
//  entity file.cpp
//  Buttons
//
//  Created by Indi Kernick on 10/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "entity file.hpp"

#include "yaml helper.hpp"
#include <Simpleton/Platform/system info.hpp>

void loadComps(
  const EntityID id,
  const YAML::Node &comps,
  const EntityIDmap &idMap,
  Registry &registry
) {
  
}

void loadEntity(
  const EntityID id,
  const std::string &entityFileName,
  const YAML::Node &levelComps,
  const EntityIDmap &idMap,
  Registry &registry
) {
  const YAML::Node comps = YAML::LoadFile(Platform::getResDir() + entityFileName);
  checkType(comps, YAML::NodeType::Map);
  checkType(levelComps, YAML::NodeType::Map);
  loadComps(id, comps, idMap, registry);
  loadComps(id, levelComps, idMap, registry);
}
