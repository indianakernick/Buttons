//
//  power system.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "power system.hpp"

#include "power component.hpp"

namespace {
  auto equalTo(const bool other) {
    return [other] (const bool value) {
      return value == other;
    };
  }

  bool logic(const PowerInput::LogicOp op, const std::vector<bool> &input) {
    switch (op) {
      case PowerInput::LogicOp::AND:
        return std::all_of(input.cbegin(), input.cend(), equalTo(true));
      case PowerInput::LogicOp::OR:
        return std::any_of(input.cbegin(), input.cend(), equalTo(true));
      case PowerInput::LogicOp::XOR:
        return std::count(input.cbegin(), input.cend(), true) == 1;
      case PowerInput::LogicOp::NAND:
        return !logic(PowerInput::LogicOp::AND, input);
      case PowerInput::LogicOp::NOR:
        return !logic(PowerInput::LogicOp::OR, input);
      case PowerInput::LogicOp::XNOR:
        return !logic(PowerInput::LogicOp::XOR, input);
      case PowerInput::LogicOp::NOT:
        if (input.size() == 1) {
          return !input[0];
        } else {
          throw std::runtime_error("NOT operator expects a single input");
        }
      case PowerInput::LogicOp::IDENTITY:
        if (input.size() == 1) {
          return input[0];
        } else {
          throw std::runtime_error("IDENTITY operator expects a single input");
        }
      default:
        assert(false);
    }
  }
}

void powerSystem(Registry &registry) {
  static std::vector<bool> inputs;

  const auto powerOutput = registry.view<PowerOutput>();
  auto powerInput = registry.view<PowerInput>();
  
  for (const EntityID entity : powerInput) {
    PowerInput &input = powerInput.get(entity);
    if (!input.inputs.empty()) {
      inputs.clear();
      for (const EntityID in : input.inputs) {
        inputs.push_back(powerOutput.get(in).on);
      }
      input.on = logic(input.op, inputs);
    }
  }
}
