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
#include <Simpleton/ECS/registry.hpp>

struct PowerInput {
  enum class LogicOp {
    AND,
    OR,
    XOR,
    NAND,
    NOR,
    XNOR,
    NOT,
    IDENTITY
  };

  std::vector<ECS::EntityID> inputs;
  LogicOp op;
  bool on = false;
};

struct PowerOutput {
  bool on = false;
};

#endif
