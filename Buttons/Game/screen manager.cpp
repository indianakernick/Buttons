//
//  screen manager.cpp
//  Buttons
//
//  Created by Indi Kernick on 27/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "screen manager.hpp"

void ScreenManager::removeAll() {
  for (auto &pair : screens) {
    pair.second->screenMan = nullptr;
  }
  screens.clear();
  current = nullptr;
}

void ScreenManager::initAll(RenderingContext &renderingContext) {
  for (auto &pair : screens) {
    pair.second->init(renderingContext);
  }
}

void ScreenManager::quitAll() {
  for (auto &pair : screens) {
    pair.second->quit();
  }
}

void ScreenManager::input(const SDL_Event &e) {
  if (current) {
    current->input(e);
  }
}

void ScreenManager::update(const float delta) {
  if (current) {
    current->update(delta);
  }
}

glm::mat3 ScreenManager::preRender(const glm::ivec2 windowSize, const float delta) {
  if (current) {
    return current->preRender(windowSize, delta);
  } else {
    return {};
  }
}

void ScreenManager::render(NVGcontext *const ctx, const float delta) {
  if (current) {
    current->render(ctx, delta);
  }
}

void ScreenManager::transitionTo(const ScreenID next) {
  current = screens.at(next).get();
  current->enter();
}
