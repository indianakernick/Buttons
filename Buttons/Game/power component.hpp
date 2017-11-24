//
//  power component.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef power_component_hpp
#define power_component_hpp

#include <vector>
#include "entity constants.hpp"

struct PowerInput {
  EntityID input;
  bool invert = false;
  bool on = false;
};

struct MultiPowerInput {
  enum class LogicOp {
    AND,
    OR,
    XOR,
    NAND,
    NOR,
    XNOR
  };

  std::vector<EntityID> inputs;
  LogicOp op;
  bool on = false;
};

struct PowerOutput {
  bool on = false;
};

#endif
