//
//  app.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "app.hpp"

#include "game screen.hpp"
#include "global flags.hpp"
#include "window constants.hpp"
#include "start menu screen.hpp"
#include <Simpleton/Time/get.hpp>

void App::mainloop() {
  init();
  
  //Time::Mainloop::fixedWithVarPrePost isn't perfect
  
  //the application cannot control the mainloop properly so I'll have to
  //find another way of implementing the interface to Time::Mainloop
  
  static const float step = 1.0f/60.0f;
  static const uint32_t maxSteps = 16;
  
  Rep lag = 0;
  Time::Point<Duration> last = Time::getPoint<Duration>();
  bool ok = true;

  while (ok) {
    const Time::Point<Duration> now = Time::getPoint<Duration>();
    const Duration elapsed = now - last;
    last = now;
    lag += elapsed.count();
    
    uint32_t numSteps = lag < 0 ? 0 : std::min(static_cast<uint32_t>(lag / step), maxSteps);
    const Rep stepSize = step * numSteps;
    lag -= stepSize;
    
    ok = input(stepSize);
    
    while (numSteps) {
      ok = ok && update(step);
      numSteps--;
    }
    
    ok = ok && render(stepSize);
  }
  
  quit();
}

void App::init() {
  windowLibrary.emplace(SDL_INIT_EVENTS);
  window = Platform::makeWindow(WINDOW_DESC);
  renderingContext.init(window.get(), WINDOW_VSYNC);
  
  screens.addScreen<GameScreen>();
  screens.addScreen<StartMenuScreen>();
  screens.transitionTo<StartMenuScreen>();
  
  screens.initAll(renderingContext);
}

void App::quit() {
  screens.quitAll();

  renderingContext.quit();
  window.reset();
  windowLibrary = std::experimental::nullopt;
}

bool App::input(float) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      return false;
    } else {
      screens.input(e);
    }
  }
  return true;
}

bool App::update(const float delta) {
  screens.update(delta);
  return true;
}

bool App::render(const float delta) {
  const glm::ivec2 frameSize = renderingContext.getFrameSize();
  const glm::mat3 mat = screens.preRender(frameSize, delta);
  renderingContext.preRender();
  //screens.render(renderingContext.getRenderer(), delta);
  renderingContext.postRender();
  return true;
}
