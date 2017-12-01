//
//  event helper.cpp
//  Buttons
//
//  Created by Indi Kernick on 1/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "event helper.hpp"

#include <SDL2/SDL_events.h>

bool keyDown(const SDL_Event &e, const SDL_Scancode scancode) {
  return e.type == SDL_KEYDOWN && e.key.repeat == 0 && e.key.keysym.scancode == scancode;
}

bool keyUp(const SDL_Event &e, const SDL_Scancode scancode) {
  return e.type == SDL_KEYUP && e.key.keysym.scancode == scancode;
}

bool keyDown(const SDL_Event &e) {
  return e.type == SDL_KEYDOWN && e.key.repeat == 0;
}

bool keyUp(const SDL_Event &e) {
  return e.type == SDL_KEYUP;
}

SDL_Scancode keyCode(const SDL_Event &e) {
  return e.key.keysym.scancode;
}
