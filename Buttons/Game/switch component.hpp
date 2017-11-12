//
//  switch component.hpp
//  Buttons
//
//  Created by Indi Kernick on 12/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef switch_component_hpp
#define switch_component_hpp

#include "entity constants.hpp"

namespace YAML {
  class Node;
}
class EntityIDmap;

struct Switch {
  Switch(const YAML::Node &, const EntityIDmap &);
  
  EntityID player;
};

#endif
