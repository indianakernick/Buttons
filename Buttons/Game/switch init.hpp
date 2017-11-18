//
//  switch init.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef switch_init_hpp
#define switch_init_hpp

#include "comp init.hpp"
#include "switch component.hpp"

class SwitchInit : CompInit<Switch> {
public:
  void init(Switch &, const YAML::Node &, const EntityIDmap &, EntityID);
};

#endif
