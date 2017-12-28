//
//  static sprite rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 22/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef static_sprite_rendering_system_hpp
#define static_sprite_rendering_system_hpp

#include "rendering helpers.hpp"
#include <Simpleton/ECS/registry.hpp>

size_t countStaticSprites(ECS::Registry &);
void writeStaticSprites(ECS::Registry &, const Spritesheet &, QuadIter &);

#endif
