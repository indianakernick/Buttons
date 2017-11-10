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

void loadEntity(
  const std::string &entityFileName,
  const YAML::Node &levelComps,
  EntityIDmap &idMap,
  Registry &registry
) {
  const YAML::Node comps = YAML::LoadFile(Platform::getResDir() + entityFileName);
  checkType(comps, YAML::NodeType::Map);
  checkType(levelComps, YAML::NodeType::Map);
  loadComps(comps, idMap, registry);
  loadComps(levelComps, idMap, registry);
}
