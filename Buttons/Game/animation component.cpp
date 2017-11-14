//
//  animation component.cpp
//  Buttons
//
//  Created by Indi Kernick on 12/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "animation component.hpp"

#include "yaml helper.hpp"

Animation::Animation(const YAML::Node &node, const EntityIDmap &) {
  getOptional(progress, node, "progress");
  getOptional(speed, node, "speed");
  
  if (const YAML::Node &edgeModeNode = node["edge mode"]) {
    const std::string &edgeModeStr = edgeModeNode.Scalar();
    if (edgeModeStr == "repeat") {
      edgeMode = EdgeMode::REPEAT;
    } else if (edgeModeStr == "change dir") {
      edgeMode = EdgeMode::CHANGE_DIR;
    }
  }
}
