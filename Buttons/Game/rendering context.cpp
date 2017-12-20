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
  params.majorVersion = 4;
  params.minorVersion = 1;
  context = GL::makeContext(window, params);
  
  glDisable(GL_CULL_FACE);
  glDisable(GL_DEPTH_TEST);
}

void RenderingContext::quit() {
  context = nullptr;
  window = nullptr;
}

void RenderingContext::preRender() {
  // @TODO
  // emulate a retina display with a device pixel ratio of 2
  // sudo defaults write /Library/Preferences/com.apple.windowserver DisplayResolutionEnabled -bool YES
  glm::ivec2 size;
  SDL_GL_GetDrawableSize(window, &size.x, &size.y);
  glViewport(0, 0, size.x, size.y);
  CHECK_OPENGL_ERROR();
  
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
