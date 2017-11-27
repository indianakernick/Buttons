//
//  start menu screen.cpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "start menu screen.hpp"

#include "nvg helper.hpp"
#include <SDL2/SDL_events.h>
#include "rendering context.hpp"
#include <Simpleton/Camera 2D/zoom to fit.hpp>

ScreenID StartMenuScreen::getID() const {
  return ScreenID::START_MENU;
}

ScreenID StartMenuScreen::getNextScreen() const {
  if (startGame) {
    return ScreenID::GAME;
  } else {
    return ScreenID::START_MENU;
  }
}

void StartMenuScreen::enter() {}

void StartMenuScreen::leave() {}

void StartMenuScreen::init(RenderingContext &renderingContext) {
  camera.transform.setInvertY(true);
  camera.transform.setOrigin(Cam2D::Origin::CENTER);
  camera.targetZoom = std::make_unique<Cam2D::ZoomToFit>(glm::vec2(16, 9));
  font = renderingContext.getResources().getFont("Arial.ttf");
  
  startButton.setCenterSize({0.0f, 0.0f}, {8.0f, 2.0f});
  startButton.setText("Start");
  startButton.setFont(font);
  startButton.setFontSize(80.0f);
  startButton.setTopColor(nvgRGBf(0.5f, 1.0f, 0.5f));
  startButton.setBottomColor(nvgRGBf(0.0f, 0.5f, 0.0f));
  startButton.setCornerRadius(0.5f);
  
  inputDispatcher.addListener([this] (const SDL_Event &e) {
    if (e.type == SDL_MOUSEBUTTONUP) {
      const glm::vec2 posPx = {e.button.x, e.button.y};
      const glm::vec2 posM = camera.transform.toMeters(posPx);
      if (startButton.hit(posM)) {
        startGame = true;
        return true;
      }
    }
    return false;
  });
  
  resetButton.setCenterSize({0.0f, -2.0f}, {4.0f, 1.0f});
  resetButton.setText("Reset");
  resetButton.setFont(font);
  resetButton.setFontSize(40.0f);
  resetButton.setTopColor(nvgRGBf(1.0f, 0.5f, 0.5f));
  resetButton.setBottomColor(nvgRGBf(0.5f, 0.0f, 0.0f));
  resetButton.setCornerRadius(0.25f);
  
  inputDispatcher.addListener([this] (const SDL_Event &e) {
    if (e.type == SDL_MOUSEBUTTONUP) {
      const glm::vec2 posPx = {e.button.x, e.button.y};
      const glm::vec2 posM = camera.transform.toMeters(posPx);
      if (resetButton.hit(posM)) {
        //progressManager.reset();
        return true;
      }
    }
    return false;
  });
}

void StartMenuScreen::quit() {
  inputDispatcher.clearListeners();
  
  resetButton.setFont(nullptr);
  startButton.setFont(nullptr);
  font = nullptr;
}

void StartMenuScreen::input(const SDL_Event &e) {
  inputDispatcher.dispatch(e);
}

void StartMenuScreen::update(const float) {}

glm::mat3 StartMenuScreen::preRender(const glm::ivec2 windowSize, const float delta) {
  camera.update(windowSize, delta);
  return camera.transform.toPixels();
}

void StartMenuScreen::render(NVGcontext *const ctx, const float) {
  startButton.render(ctx);
  resetButton.render(ctx);
}
