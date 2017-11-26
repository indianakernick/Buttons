//
//  text rendering component.hpp
//  Buttons
//
//  Created by Indi Kernick on 20/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef text_rendering_component_hpp
#define text_rendering_component_hpp

#include "nanovg.hpp"
#include "rendering resources.hpp"

struct TextRendering {
  FontHandle font;
  NVGcolor color;
  int align;
  float size;
};

#endif
