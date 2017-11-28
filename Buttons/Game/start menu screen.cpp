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
  
  {
    ButtonStyle startButtonStyle;
    startButtonStyle.top = nvgRGBf(0.5f, 1.0f, 0.5f);
    startButtonStyle.bottom = nvgRGBf(0.0f, 0.5f, 0.0f);
    startButtonStyle.cornerRadius = 0.5f;
    startButton.style(startButtonStyle);
  }
  startButton.rect({0.0f, 0.0f}, {8.0f, 2.0f});
  startText.rect(startButton.rect());
  
  TextStyle textStyle;
  textStyle.font = font;
  textStyle.size = 80.0f;
  
  startText.style(textStyle);
  startText.text("Start");
  
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
  
  {
    ButtonStyle resetButtonStyle;
    resetButtonStyle.top = nvgRGBf(1.0f, 0.5f, 0.5f);
    resetButtonStyle.bottom = nvgRGBf(0.5f, 0.0f, 0.0f);
    resetButtonStyle.cornerRadius = 0.25f;
    resetButton.style(resetButtonStyle);
  }
  resetButton.rect({0.0f, -2.0f}, {4.0f, 1.0f});
  resetText.rect(resetButton.rect());
  
  textStyle.size = 40.0f;
  resetText.style(textStyle);
  resetText.text("Reset");
  
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
  
  textStyle.size = 120.0f;
  buttonsText.style(textStyle);
  buttonsText.text("Buttons");
  buttonsText.rect({0.0f, 2.0f}, {1.0f, 1.0f});
}

void StartMenuScreen::quit() {
  inputDispatcher.clearListeners();
  
  resetText.nullFont();
  startText.nullFont();
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
  startText.render(ctx);
  resetText.render(ctx);
  buttonsText.render(ctx);
}
