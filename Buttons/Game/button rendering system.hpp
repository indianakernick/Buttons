//
//  button rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 12/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef button_rendering_system_hpp
#define button_rendering_system_hpp

#include "entity registry.hpp"

extern "C" struct NVGcontext;

void buttonRenderingSystem(Registry &, NVGcontext *);

#endif
