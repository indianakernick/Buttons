//
//  activation init.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef activation_init_hpp
#define activation_init_hpp

#include "comp init.hpp"
#include "activation component.hpp"

class ActivationInit : CompInit<Activation> {
public:
  void init(Activation &, const YAML::Node &, const EntityIDmap &, EntityID);
};

#endif
