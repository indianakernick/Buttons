//
//  laser rendering init.cpp
//  Buttons
//
//  Created by Indi Kernick on 22/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "laser rendering init.hpp"

void LaserRenderingInit::init(LaserRendering &comp, const json &node) {
  comp.depth = node.at("depth").get<float>();
}
