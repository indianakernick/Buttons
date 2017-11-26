//
//  shadow rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef shadow_rendering_system_hpp
#define shadow_rendering_system_hpp

#include "entity registry.hpp"

extern "C" struct NVGcontext;

void shadowRenderingSystem(Registry &, NVGcontext *);

#endif
