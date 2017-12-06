//
//  render grid.cpp
//  Buttons
//
//  Created by Indi Kernick on 24/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "render grid.hpp"

#include "nvg helper.hpp"
#include "camera constants.hpp"

void renderGrid(NVGcontext *const ctx) {
  nvgBeginPath(ctx);
  nvgStrokeWidth(ctx, 0.05f);
  nvgStrokeColor(ctx, nvgRGBf(0.1f, 0.1f, 0.1f));
  
  for (float x = 1.0f; x < LEVEL_SIZE.x; ++x) {
    nvgMoveTo(ctx, x, 0.0f);
    nvgLineTo(ctx, x, LEVEL_SIZE.y);
  }
  
  for (float y = 1.0f; y < LEVEL_SIZE.y; ++y) {
    nvgMoveTo(ctx, 0.0f, y);
    nvgLineTo(ctx, LEVEL_SIZE.x, y);
  }
  
  nvgStroke(ctx);
}
