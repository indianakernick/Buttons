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

void LevelManager::init(ECS::Registry &newRegistry, const ECS::CompInits<CompList> &newCompInits) {
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
  const std::string levelStr = level == FINAL ? "final" : std::to_string(level);
  if (::loadLevel("level " + levelStr + ".json", *compInits, *registry)) {
    current = level;
    return true;
  } else {
    return false;
  }
}

bool LevelManager::loadFinalLevel() {
  return loadLevel(FINAL);
}

bool LevelManager::nextLevel() {
  if (current == NONE_LOADED) {
    return loadLevel(0);
  } else {
    if (loadLevel(current + 1)) {
      return true;
    } else {
      return loadFinalLevel();
    }
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

Level LevelManager::getLoaded() const {
  return current;
}

bool LevelManager::isLoaded() const {
  return current != NONE_LOADED;
}
