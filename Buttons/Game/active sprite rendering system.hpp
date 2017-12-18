//
//  active sprite rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef active_sprite_rendering_system_hpp
#define active_sprite_rendering_system_hpp

#include <glm/mat3x3.hpp>
#include "entity registry.hpp"

namespace Unpack {
  class Spritesheet;
}
extern "C" struct SDL_Texture;
extern "C" struct SDL_Renderer;

void activeSpriteRenderingSystem(
  Registry &,
  SDL_Renderer *,
  SDL_Texture *,
  Unpack::Spritesheet &,
  glm::mat3
);

#endif
