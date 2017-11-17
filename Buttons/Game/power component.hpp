//
//  power component.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef power_component_hpp
#define power_component_hpp

#include "entity constants.hpp"

namespace YAML {
  class Node;
}
class EntityIDmap;

struct PowerInput {
  PowerInput(const YAML::Node &, const EntityIDmap &);

  bool on = false;
  EntityID in;
};

struct PowerOutput {
  bool on = false;
};

#endif
