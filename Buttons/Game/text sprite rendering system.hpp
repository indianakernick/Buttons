//
//  text sprite rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 23/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef text_sprite_rendering_system_hpp
#define text_sprite_rendering_system_hpp

#include "entity registry.hpp"
#include "rendering helpers.hpp"

size_t countTextSprites(Registry &);
void writeTextSprites(Registry &, const Spritesheet &, QuadIter &);

#endif
