//
//  static sprite rendering component.hpp
//  Buttons
//
//  Created by Indi Kernick on 21/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef static_sprite_rendering_component_hpp
#define static_sprite_rendering_component_hpp

#include <glm/vec2.hpp>
#include <Unpacker/unpacker.hpp>

struct StaticSpriteRendering {
  Unpack::SpriteID sprite;
  float depth;
};

#endif
