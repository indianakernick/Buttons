//
//  progress manager.cpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "progress manager.hpp"

#include "dir.hpp"

ProgressManager::ProgressManager() {
  std::ifstream file(getSaveDir() + "progress.txt");
  if (!file.is_open()) {
    currentLevel = 0;
  } else {
    file >> currentLevel;
  }
}

ProgressManager::~ProgressManager() {
  std::ofstream file(getSaveDir() + "progress.txt");
  if (file.is_open()) {
    file << currentLevel;
  }
}

Level ProgressManager::getCurrentLevel() const {
  return currentLevel;
}

void ProgressManager::finishLevel() {
  ++currentLevel;
}

void ProgressManager::reset() {
  currentLevel = 0;
}
