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

void LevelManager::init(Registry &newRegistry, const CompInits &newCompInits) {
  assert(!registry);
  registry = &newRegistry;
  compInits = &newCompInits;
}

void LevelManager::quit() {
  assert(registry);
  compInits = nullptr;
  registry = nullptr;
}

bool LevelManager::loadLevel(const Level level) {
  assert(registry);
  if (current != NONE_LOADED) {
    registry->reset();
  }
  if (::loadLevel("level " + std::to_string(level) + ".yaml", *registry, *compInits)) {
    current = level;
    return true;
  } else {
    return false;
  }
}

bool LevelManager::nextLevel() {
  if (current == NONE_LOADED) {
    return loadLevel(0);
  } else {
    return loadLevel(current + 1);
  }
}

bool LevelManager::reload() {
  if (current != NONE_LOADED) {
    loadLevel(current);
    return true;
  } else {
    return false;
  }
}
