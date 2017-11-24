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

  bool logic(const MultiPowerInput::LogicOp op, const std::vector<bool> &input) {
    switch (op) {
      case MultiPowerInput::LogicOp::AND:
        return std::all_of(input.cbegin(), input.cend(), equalTo(true));
      case MultiPowerInput::LogicOp::OR:
        return std::any_of(input.cbegin(), input.cend(), equalTo(true));
      case MultiPowerInput::LogicOp::XOR:
        return std::count(input.cbegin(), input.cend(), true) == 1;
      case MultiPowerInput::LogicOp::NAND:
        return !logic(MultiPowerInput::LogicOp::AND, input);
      case MultiPowerInput::LogicOp::NOR:
        return !logic(MultiPowerInput::LogicOp::OR, input);
      case MultiPowerInput::LogicOp::XNOR:
        return !logic(MultiPowerInput::LogicOp::XOR, input);
      default:
        assert(false);
    }
  }
}

void powerSystem(Registry &registry) {
  static std::vector<bool> inputs;

  const auto powerOutput = registry.view<PowerOutput>();
  auto powerInput = registry.view<PowerInput>();
  auto multiPowerInput = registry.view<MultiPowerInput>();
  
  for (const EntityID entity : powerInput) {
    PowerInput &input = powerInput.get(entity);
    if (input.input != NULL_ENTITY) {
      input.on = powerOutput.get(input.input).on;
      if (input.invert) {
        input.on = !input.on;
      }
    }
  }
  
  for (const EntityID entity : multiPowerInput) {
    MultiPowerInput &input = multiPowerInput.get(entity);
    if (!input.inputs.empty()) {
      inputs.clear();
      for (const EntityID in : input.inputs) {
        inputs.push_back(powerOutput.get(in).on);
      }
      input.on = logic(input.op, inputs);
    }
  }
}
