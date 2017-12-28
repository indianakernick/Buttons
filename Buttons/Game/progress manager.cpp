//
//  progress manager.cpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "progress manager.hpp"

#include <Simpleton/SDL/paths.hpp>

namespace {
  std::string getSaveDir() {
    return SDL::getSaveDir("Indi Kernick", "Buttons");
  }
}

ProgressManager::ProgressManager() {
  std::ifstream file(getSaveDir() + "progress.txt");
  if (!file.is_open()) {
    numCompleted = 0;
  } else {
    file >> numCompleted;
  }
}

ProgressManager::~ProgressManager() {
  std::ofstream file(getSaveDir() + "progress.txt");
  if (file.is_open()) {
    file << numCompleted;
  }
}

Level ProgressManager::getIncompleteLevel() const {
  return numCompleted;
}

bool ProgressManager::hasCompleted(const Level level) const {
  return level < numCompleted;
}

void ProgressManager::finishLevel(const Level level) {
  if (numCompleted == level) {
    ++numCompleted;
  }
}

void ProgressManager::reset() {
  numCompleted = 0;
}
