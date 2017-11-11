//
//  box rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 11/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef box_rendering_system_hpp
#define box_rendering_system_hpp

#include "entity registry.hpp"

extern "C" struct NVGcontext;

void boxRenderingSystem(Registry &, NVGcontext *);

#endif
