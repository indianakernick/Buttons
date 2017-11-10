//
//  level file.cpp
//  Buttons
//
//  Created by Indi Kernick on 10/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "level file.hpp"

#include "entity file.hpp"
#include "yaml helper.hpp"
#include "entity id map.hpp"
#include <Simpleton/Platform/system info.hpp>

void loadLevel(const std::string &fileName, Registry &registry) {
  const YAML::Node root = YAML::LoadFile(Platform::getResDir() + fileName);
  checkType(root, YAML::NodeType::Sequence);
  EntityIDmap idMap;
  idMap.insertIDs(root, registry);
  
  for (size_t i = 0; i != root.size(); ++i) {
    const YAML::Node &node = root[i];
    const std::string &entityFile = getChild(node, "file").Scalar();
    const YAML::Node &comps = node["components"];
    loadEntity(idMap.getEntityFromIndex(i), entityFile, comps, idMap, registry);
  }
}
