//
//  comp init.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef comp_init_hpp
#define comp_init_hpp

#include "entity constants.hpp"

namespace YAML {
  class Node;
}
class EntityIDmap;

template <typename Comp>
struct CompInit {
  void init(Comp &, const YAML::Node &, const EntityIDmap &, EntityID) {}
};

#endif
