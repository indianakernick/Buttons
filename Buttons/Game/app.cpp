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
#include <Simpleton/Utils/profiler.hpp>

bool App::mainloop(const uint64_t deltaNano) {
  PROFILE(App::mainloop);
  const float deltaSec = deltaNano / 1e9f;
  
  bool ok = input(deltaSec);
  ok = ok && update(deltaSec);
  ok = ok && render(deltaSec);
  
  return ok;
}

void App::init() {
  windowLibrary = SDL::makeLibrary(SDL_INIT_EVENTS);
  window = SDL::makeWindow(WINDOW_DESC);
  renderingContext.init(window.get(), WINDOW_VSYNC);
  renderingSystem.init();
  
  screens.addScreen<GameScreen>();
  screens.addScreen<StartMenuScreen>();
  screens.transitionTo<StartMenuScreen>();
  
  screens.initAll(renderingSystem);
}

void App::quit() {
  screens.quitAll();

  renderingSystem.quit();
  renderingContext.quit();
  window.reset();
  windowLibrary.reset();
}

bool App::input(float) {
  PROFILE(App::input);
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
  PROFILE(App::update);
  screens.update(delta);
  return true;
}

bool App::render(const float delta) {
  PROFILE(App::render);
  renderingContext.preRender();
  const glm::ivec2 windowSize = window.size();
  const float aspect = static_cast<float>(windowSize.x) / windowSize.y;
  screens.render(aspect, delta);
  renderingContext.postRender();
  return true;
}
