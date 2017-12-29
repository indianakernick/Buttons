//
//  power init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "power init.hpp"

#include <Simpleton/ECS/entity id map.hpp>

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

void PowerInputInit::init(PowerInput &comp, const json &node, const ECS::EntityIDmap &idMap) {
  if (JSON_OPTIONAL(inNode, node, "in")) {
    if (inNode->is_array()) {
      for (auto &node : *inNode) {
        comp.inputs.push_back(idMap.getEntityFromID(node.get<ECS::ClientEntityID>()));
      }
    } else if (inNode->is_number()) {
      comp.inputs.push_back(idMap.getEntityFromID(inNode->get<ECS::ClientEntityID>()));
    }
  }
  if (JSON_OPTIONAL(opNode, node, "operator")) {
    comp.op = getLogicOp(opNode->get_ref<const std::string &>());
  } else {
    comp.op = PowerInput::LogicOp::IDENTITY;
  }
  Data::getOptional(comp.on, node, "on");
}
