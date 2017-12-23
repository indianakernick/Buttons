//
//  text rendering component.hpp
//  Buttons
//
//  Created by Indi Kernick on 22/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef text_rendering_component_hpp
#define text_rendering_component_hpp

#include <glm/vec2.hpp>
#include <Unpacker/unpacker.hpp>

struct TextRendering {
  glm::vec2 scale;
  Unpack::SpriteID sprite;
  float depth;
  float kern;
};

#endif
