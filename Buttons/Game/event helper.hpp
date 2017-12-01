//
//  event helper.hpp
//  Buttons
//
//  Created by Indi Kernick on 1/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef event_helper_hpp
#define event_helper_hpp

#include <SDL2/SDL_scancode.h>

extern "C" union SDL_Event;

bool keyDown(const SDL_Event &, SDL_Scancode);
bool keyUp(const SDL_Event &, SDL_Scancode);

#endif
