//
//  player input system.hpp
//  Buttons
//
//  Created by Indi Kernick on 11/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef player_input_system_hpp
#define player_input_system_hpp

#include "entity registry.hpp"

extern "C" union SDL_Event;

bool playerInputSystem(Registry &, const SDL_Event &);

#endif
