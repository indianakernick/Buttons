//
//  text rendering component.hpp
//  Buttons
//
//  Created by Indi Kernick on 22/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef text_rendering_component_hpp
#define text_rendering_component_hpp

#include <Unpacker/unpacker.hpp>

struct TextRendering {
  Unpack::SpriteID sprite;
  float depth;
  float scale;
};

#endif
