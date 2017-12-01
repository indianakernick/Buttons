//
//  animation init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "animation init.hpp"

#include "yaml helper.hpp"

void AnimationInit::init(Animation &comp, const YAML::Node &node) {
  getOptional(comp.progress, node, "progress");
  getOptional(comp.speed, node, "speed");
  
  if (const YAML::Node &edgeModeNode = node["edge mode"]) {
    const std::string &edgeModeStr = edgeModeNode.Scalar();
    if (edgeModeStr == "stop") {
      comp.edgeMode = Animation::EdgeMode::STOP;
    } else if (edgeModeStr == "repeat") {
      comp.edgeMode = Animation::EdgeMode::REPEAT;
    } else if (edgeModeStr == "change dir") {
      comp.edgeMode = Animation::EdgeMode::CHANGE_DIR;
    }
  }
}
