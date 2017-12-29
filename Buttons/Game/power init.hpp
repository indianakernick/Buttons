//
//  power init.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef power_init_hpp
#define power_init_hpp

#include "comp init.hpp"
#include "power component.hpp"

class PowerInputInit final : public CompInit<PowerInput> {
public:
  void init(PowerInput &, const json &, const ECS::EntityIDmap &) override;
};

#endif
