//
//  app.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "app.hpp"

#include <SDL2/SDL.h>

void App::mainloop() {
  SDL_Init(SDL_INIT_EVERYTHING);
  
  SDL_Window *window = SDL_CreateWindow(
    "Title",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    1280, 720,
    SDL_WINDOW_SHOWN
  );
  
  bool done = false;
  while (!done) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        done = true;
        break;
      }
    }
  }
  
  SDL_DestroyWindow(window);
  
  SDL_Quit();
}
