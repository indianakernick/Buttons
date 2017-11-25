//
//  lock rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef lock_rendering_system_hpp
#define lock_rendering_system_hpp

#include "entity registry.hpp"

extern "C" struct NVGcontext;

void lockRenderingSystem(Registry &, NVGcontext *);

#endif
