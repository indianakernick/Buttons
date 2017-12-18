//
//  start menu screen.cpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "start menu screen.hpp"

#include "game screen.hpp"
#include "text element.hpp"
#include <SDL2/SDL_events.h>
#include "screen manager.hpp"
#include "button element.hpp"
#include "rendering context.hpp"
#include <Simpleton/Camera 2D/zoom to fit.hpp>

void StartMenuScreen::init(RenderingContext &renderingContext) {
  camera.transform.setInvertY(true);
  camera.transform.setOrigin(Cam2D::Origin::CENTER);
  camera.targetZoom = std::make_unique<Cam2D::ZoomToFit>(glm::vec2(16, 9));
  
  auto startButton = std::make_unique<ButtonElement>();
  auto startText = std::make_unique<TextElement>();
  
  startButton->rect({0.0f, 0.0f}, {8.0f, 2.0f});
  startText->rect(startButton->rect());
  
  startText->text("Start");
  
  startButton->onMouseButton([this] (ButtonElement &, const MouseButtonState state) {
    if (state == MouseButtonState::RELEASED) {
      startGame = true;
      return true;
    }
    return false;
  });
  
  elementMan.addElement(std::move(startButton));
  elementMan.addElement(std::move(startText));
  
  auto resetButton = std::make_unique<ButtonElement>();
  auto resetText = std::make_unique<TextElement>();
  
  resetButton->rect({0.0f, -2.0f}, {4.0f, 1.0f});
  resetText->rect(resetButton->rect());
  
  resetText->text("Reset");
  
  resetButton->onMouseButton([this] (ButtonElement &, const MouseButtonState state) {
    if (state == MouseButtonState::RELEASED) {
      getScreenMan()->getScreen<GameScreen>().resetProgress();
      return true;
    }
    return false;
  });
  
  elementMan.addElement(std::move(resetButton));
  elementMan.addElement(std::move(resetText));
  
  auto buttonsText = std::make_unique<TextElement>();
  
  buttonsText->text("Buttons");
  buttonsText->rect({0.0f, 2.0f}, {1.0f, 1.0f});
  
  elementMan.addElement(std::move(buttonsText));
}

void StartMenuScreen::quit() {
  elementMan.remAllElements();
}

void StartMenuScreen::input(const SDL_Event &e) {
  elementMan.handleEvent(e, camera.transform.toMeters());
}

void StartMenuScreen::update(const float) {}

glm::mat3 StartMenuScreen::preRender(const glm::ivec2 windowSize, const float delta) {
  camera.update(windowSize, delta);
  return camera.transform.toPixels();
}

void StartMenuScreen::render(SDL_Renderer *const ctx, const float) {
  elementMan.render(ctx);
  
  if (startGame) {
    getScreenMan()->transitionTo<GameScreen>();
    startGame = false;
  }
}
