//
//  text sprite rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 23/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef text_sprite_rendering_system_hpp
#define text_sprite_rendering_system_hpp

#include "rendering helpers.hpp"
#include <Simpleton/ECS/registry.hpp>

size_t countTextSprites(ECS::Registry &);
void writeTextSprites(ECS::Registry &, const Spritesheet &, QuadIter &);

#endif
