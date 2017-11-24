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
  
  const float halfWidth = LEVEL_SIZE.x / 2.0f;
  const float halfHeight = LEVEL_SIZE.y / 2.0f;
  
  for (float x = -halfWidth + 1.0f; x < halfWidth; ++x) {
    nvgMoveTo(ctx, x, halfHeight);
    nvgLineTo(ctx, x, -halfHeight);
  }
  
  for (float y = -halfHeight + 1.0f; y < halfHeight; ++y) {
    nvgMoveTo(ctx, halfWidth, y);
    nvgLineTo(ctx, -halfWidth, y);
  }
  
  nvgStroke(ctx);
}
