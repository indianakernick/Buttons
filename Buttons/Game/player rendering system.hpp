//
//  player rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 11/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef player_rendering_system_hpp
#define player_rendering_system_hpp

#include "entity registry.hpp"

extern "C" struct NVGcontext;

void playerRenderingSystem(Registry &, NVGcontext *);


#endif
