//
//  render polygon.hpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef render_polygon_hpp
#define render_polygon_hpp

extern "C" struct NVGcontext;

void renderPolygon(NVGcontext *, unsigned sides, float radius, float rotation = 0.0f);

#endif
