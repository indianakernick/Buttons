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
  MultiPowerInput::LogicOp getLogicOp(const std::string &name) {
           if (name == "and") {
      return MultiPowerInput::LogicOp::AND;
    } else if (name == "or") {
      return MultiPowerInput::LogicOp::OR;
    } else if (name == "xor") {
      return MultiPowerInput::LogicOp::XOR;
    } else if (name == "nand") {
      return MultiPowerInput::LogicOp::NAND;
    } else if (name == "nor") {
      return MultiPowerInput::LogicOp::NOR;
    } else if (name == "xnor") {
      return MultiPowerInput::LogicOp::XNOR;
    } else {
      throw std::runtime_error("Invalid logical operator name");
    }
  }
}

void PowerInputInit::init(PowerInput &comp, const json &node, const EntityIDmap &idMap) {
  if (const auto inNode = node.find("in"); inNode != node.cend()) {
    comp.input = idMap.getEntityFromUserID(inNode->get<UserID>());
  } else {
    comp.input = NULL_ENTITY;
  }
  getOptional(comp.invert, node, "invert");
  getOptional(comp.on, node, "on");
}

void MultiPowerInputInit::init(MultiPowerInput &comp, const json &node, const EntityIDmap &idMap) {
  if (const auto inNode = node.find("in"); inNode != node.cend()) {
    if (inNode->is_array()) {
      for (auto &node : *inNode) {
        comp.inputs.push_back(idMap.getEntityFromUserID(node.get<UserID>()));
      }
    } else if (inNode->is_number()) {
      comp.inputs.push_back(idMap.getEntityFromUserID(inNode->get<UserID>()));
    }
  }
  comp.op = getLogicOp(getChild(node, "operator").Scalar());
  getOptional(comp.on, node, "on");
}
