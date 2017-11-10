//
//  power component.cpp
//  Buttons
//
//  Created by Indi Kernick on 9/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "power component.hpp"

#include "component init.hpp"

template <>
struct ComponentInit<PowerOutput> {
  static void init(PowerOutput &comp, const YAML::Node &node) {
    comp.on = false;
    
  }
};
