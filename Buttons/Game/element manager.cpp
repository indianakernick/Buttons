//
//  element manager.cpp
//  Buttons
//
//  Created by Indi Kernick on 28/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "element manager.hpp"

#include <SDL2/SDL_events.h>

bool ElementManager::handleEvent(const SDL_Event &e, const glm::mat3 &toMeters) {
  if (e.type == SDL_MOUSEBUTTONUP || e.type == SDL_MOUSEBUTTONDOWN) {
    for (auto &elem : elements) {
      if (elem->handleMouseButton(e.button, toMeters)) {
        return true;
      }
    }
  }
  return false;
}

void ElementManager::render(NVGcontext *const ctx) {
  for (auto &e : elements) {
    e->render(ctx);
  }
}

void ElementManager::addElement(std::unique_ptr<Element> &&element) {
  elements.emplace_back(std::move(element));
}

void ElementManager::remAllElements() {
  elements.clear();
}
