//
//  anim sprite rendering component.hpp
//  Buttons
//
//  Created by Indi Kernick on 21/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef anim_sprite_rendering_component_hpp
#define anim_sprite_rendering_component_hpp

#include <unpacker.hpp>
#include <glm/vec2.hpp>

struct AnimSpriteRendering {
  Unpack::SpriteID sprite;
  Unpack::SpriteID frames;
  glm::vec2 offset = {0.0f, 0.0f};
  glm::vec2 scale = {1.0f, 1.0f};
  float depth;
};

#endif
