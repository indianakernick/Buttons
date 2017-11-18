//
//  level manager.cpp
//  Buttons
//
//  Created by Indi Kernick on 17/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "level manager.hpp"

#include <cassert>
#include "level file.hpp"

void LevelManager::init(Registry &newRegistry) {
  assert(!registry);
  registry = &newRegistry;
}

void LevelManager::quit() {
  assert(registry);
  registry->reset();
  registry = nullptr;
}

void LevelManager::loadLevel(const unsigned level) {
  assert(registry);
  if (current != NONE_LOADED) {
    registry->reset();
  }
  
}
