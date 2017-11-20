//
//  text rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 20/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef text_rendering_system_hpp
#define text_rendering_system_hpp

#include "entity registry.hpp"

extern "C" struct NVGcontext;

void textRenderingSystem(Registry &, NVGcontext *);

#endif
