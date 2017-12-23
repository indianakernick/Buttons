//
//  anim sprite rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 22/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef anim_sprite_rendering_system_hpp
#define anim_sprite_rendering_system_hpp

#include "entity registry.hpp"
#include "rendering helpers.hpp"

size_t countAnimSprites(Registry &);
void writeAnimSprites(Registry &, const Spritesheet &, QuadIter);

#endif
