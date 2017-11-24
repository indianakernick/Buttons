//
//  power init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "power init.hpp"

#include "yaml helper.hpp"
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

void PowerInputInit::init(PowerInput &comp, const YAML::Node &node, const EntityIDmap &idMap) {
  if (const YAML::Node &inNode = node["in"]) {
    comp.input = idMap.getEntityFromUserID(inNode.as<UserID>());
  } else {
    comp.input = NULL_ENTITY;
  }
  getOptional(comp.invert, node, "invert");
  getOptional(comp.on, node, "on");
}

void MultiPowerInputInit::init(MultiPowerInput &comp, const YAML::Node &node, const EntityIDmap &idMap) {
  if (const YAML::Node &inNode = node["in"]) {
    if (inNode.IsSequence()) {
      for (auto &node : inNode) {
        comp.inputs.push_back(idMap.getEntityFromUserID(node.as<UserID>()));
      }
    } else if (inNode.IsScalar()) {
      comp.inputs.push_back(idMap.getEntityFromUserID(node.as<UserID>()));
    }
  }
  comp.op = getLogicOp(getChild(node, "operator").Scalar());
  getOptional(comp.on, node, "on");
}
