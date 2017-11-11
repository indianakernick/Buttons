//
//  entity file.hpp
//  Buttons
//
//  Created by Indi Kernick on 10/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef entity_file_hpp
#define entity_file_hpp

#include <yaml-cpp/yaml.h>
#include "entity id map.hpp"
#include "entity registry.hpp"

class PhysicsSystem;

//@TODO too many parameters
void loadEntity(
  EntityID,
  const std::string &,
  const YAML::Node &,
  const EntityIDmap &,
  Registry &,
  PhysicsSystem &
);

#endif
