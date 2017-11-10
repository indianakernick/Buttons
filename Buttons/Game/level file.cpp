//
//  level file.cpp
//  Buttons
//
//  Created by Indi Kernick on 10/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "level file.hpp"

#include "yaml helper.hpp"
#include "entity id map.hpp"
#include <Simpleton/Platform/system info.hpp>

void loadLevel(const std::string &fileName, Registry &registry) {
  const YAML::Node root = YAML::LoadFile(Platform::getResDir() + fileName);
  checkType(root, YAML::NodeType::Sequence);
  EntityIDmap idMap;
  idMap.insertIDs(root, registry);
}
