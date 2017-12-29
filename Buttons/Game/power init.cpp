//
//  power init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "power init.hpp"

#include "entity id map.hpp"

namespace {
  PowerInput::LogicOp getLogicOp(const std::string &name) {
           if (name == "and") {
      return PowerInput::LogicOp::AND;
    } else if (name == "or") {
      return PowerInput::LogicOp::OR;
    } else if (name == "xor") {
      return PowerInput::LogicOp::XOR;
    } else if (name == "nand") {
      return PowerInput::LogicOp::NAND;
    } else if (name == "nor") {
      return PowerInput::LogicOp::NOR;
    } else if (name == "xnor") {
      return PowerInput::LogicOp::XNOR;
    } else if (name == "not") {
      return PowerInput::LogicOp::NOT;
    } else {
      throw std::runtime_error("Invalid logical operator name");
    }
  }
}

void PowerInputInit::init(PowerInput &comp, const json &node, const EntityIDmap &idMap) {
  if (const auto inNode = node.find("in"); inNode != node.cend()) {
    if (inNode->is_array()) {
      for (auto &node : *inNode) {
        comp.inputs.push_back(idMap.getEntityFromID(node.get<ClientEntityID>()));
      }
    } else if (inNode->is_number()) {
      comp.inputs.push_back(idMap.getEntityFromID(inNode->get<ClientEntityID>()));
    }
  }
  if (const auto opNode = node.find("operator"); opNode != node.cend()) {
    comp.op = getLogicOp(opNode->get_ref<const std::string &>());
  } else {
    comp.op = PowerInput::LogicOp::IDENTITY;
  }
  Data::getOptional(comp.on, node, "on");
}
