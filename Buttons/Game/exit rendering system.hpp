//
//  exit rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 14/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef exit_rendering_system_hpp
#define exit_rendering_system_hpp

#include "entity registry.hpp"

extern "C" struct NVGcontext;

void exitRenderingSystem(Registry &, NVGcontext *);

#endif
