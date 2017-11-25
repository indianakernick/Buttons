//
//  render polygon.cpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "render polygon.hpp"

#include "nvg helper.hpp"
#include <Simpleton/Math/vectors.hpp>

void renderPolygon(
  NVGcontext *const ctx,
  const unsigned sides,
  const float radius,
  const float rotation
) {
  if (sides == 0) {
    return;
  }
  
  float angle = rotation;
  const float sideAngle = 2.0f * NVG_PI / sides;
  nvgMoveTo(ctx, Math::angleMag(angle, radius));
  for (unsigned s = 1; s != sides; ++s) {
    angle += sideAngle;
    nvgLineTo(ctx, Math::angleMag(angle, radius));
  }
}
