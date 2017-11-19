//
//  laser emitter rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 19/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef laser_emitter_rendering_system_hpp
#define laser_emitter_rendering_system_hpp

#include "entity registry.hpp"

extern "C" struct NVGcontext;

void laserEmitterRenderingSystem(Registry &, NVGcontext *);

#endif
