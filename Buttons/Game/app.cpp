//
//  app.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "app.hpp"

#include "systems.hpp"
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
  const Platform::Window::Desc WINDOW_DESC = {
    "Buttons",
    {1280, 720},
    true,
    true
  };

  windowLibrary.emplace(SDL_INIT_EVENTS);
  window = Platform::makeWindow(WINDOW_DESC);
  renderingContext.init(window.get());
  renderingManager.init(renderingContext);
  
  physics.init(registry);
}

void App::quit() {
  physics.quit();

  renderingManager.quit();
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
      
    }
  }
  return true;
}

bool App::update(const float delta) {
  physics.step(delta);
  physicsTransformSystem(registry);
  powerInputActivationSystem(registry);
  activatePowerOutputSystem(registry);
  powerSystem(registry);
  buttonSystem(registry);
  
  return true;
}

bool App::render(const float delta) {
  renderingContext.preRender({});
  renderingManager.render();
  screenshot.postRender(renderingContext, true);
  return true;
}
