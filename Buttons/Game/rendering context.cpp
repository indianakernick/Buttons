//
//  rendering context.cpp
//  Catastrophe
//
//  Created by Indi Kernick on 4/9/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "rendering context.hpp"

#include <SDL2/SDL.h>
#include <Simpleton/Platform/sdl error.hpp>

void RenderingContext::init(SDL_Window *newWindow, const bool vsync) {
  window = newWindow;
  
  renderer = SDL_CreateRenderer(
    window,
    -1,
    SDL_RENDERER_ACCELERATED
    | (vsync * SDL_RENDERER_PRESENTVSYNC)
  );
}

void RenderingContext::quit() {
  SDL_DestroyRenderer(renderer);
  renderer = nullptr;
  window = nullptr;
}

void RenderingContext::preRender() {
  CHECK_SDL_ERROR(SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0));
  CHECK_SDL_ERROR(SDL_RenderClear(renderer));
}

void RenderingContext::postRender() {
  SDL_RenderPresent(renderer);
}

glm::ivec2 RenderingContext::getFrameSize() const {
  glm::ivec2 size;
  CHECK_SDL_ERROR(SDL_GetRendererOutputSize(renderer, &size.x, &size.y));
  return size;
}

SDL_Window *RenderingContext::getWindow() const {
  return window;
}

SDL_Renderer *RenderingContext::getRenderer() const {
  return renderer;
}
