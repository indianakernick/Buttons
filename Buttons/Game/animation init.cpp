//
//  animation init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "animation init.hpp"

void AnimationInit::init(Animation &comp, const json &node) {
  Data::getOptional(comp.progress, node, "progress");
  Data::getOptional(comp.speed, node, "speed");
  
  if (JSON_OPTIONAL(edgeMode, node, "edge mode")) {
    const std::string &edgeModeStr = edgeMode->get_ref<const std::string &>();
           if (edgeModeStr == "stop") {
      comp.edgeMode = Animation::EdgeMode::STOP;
    } else if (edgeModeStr == "repeat") {
      comp.edgeMode = Animation::EdgeMode::REPEAT;
    } else if (edgeModeStr == "change dir") {
      comp.edgeMode = Animation::EdgeMode::CHANGE_DIR;
    }
  }
}
