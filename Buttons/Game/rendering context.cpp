//
//  rendering context.cpp
//  Catastrophe
//
//  Created by Indi Kernick on 4/9/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "rendering context.hpp"

#include <SDL2/SDL.h>
#include <Simpleton/SDL/error.hpp>

void RenderingContext::init(SDL_Window *newWindow, const bool vsync) {
  window = newWindow;
  if (vsync) {
    context.initVSync(window);
  } else {
    context.init(window);
  }
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_FRAMEBUFFER_SRGB);
}

void RenderingContext::quit() {
  context.quit();
  window = nullptr;
}

void RenderingContext::preRender() {
  context.preRender();
}

void RenderingContext::postRender() {
  context.postRender();
}

glm::ivec2 RenderingContext::getFrameSize() const {
  return context.getFrameSize();
}

SDL_Window *RenderingContext::getWindow() const {
  return window;
}
