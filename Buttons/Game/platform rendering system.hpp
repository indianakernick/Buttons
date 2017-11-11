//
//  platform rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 11/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef platform_rendering_system_hpp
#define platform_rendering_system_hpp

#include "entity registry.hpp"

extern "C" struct NVGcontext;

void platformRenderingSystem(Registry &, NVGcontext *);

#endif
