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
  GL::ContextParams params;
  params.vsync = vsync;
  params.majorVersion = 3;
  params.minorVersion = 3;
  context = GL::makeContext(window, params);
  
  glDisable(GL_CULL_FACE);
}

void RenderingContext::quit() {
  context = nullptr;
  window = nullptr;
}

void RenderingContext::preRender() {
  GL::clearFrame();
}

void RenderingContext::postRender() {
  SDL_GL_SwapWindow(window);
}

glm::ivec2 RenderingContext::getFrameSize() const {
  glm::ivec2 size;
  SDL_GL_GetDrawableSize(window, &size.x, &size.y);
  return size;
}

SDL_Window *RenderingContext::getWindow() const {
  return window;
}
