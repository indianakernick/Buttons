//
//  level manager.hpp
//  Buttons
//
//  Created by Indi Kernick on 17/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef level_manager_hpp
#define level_manager_hpp

#include <limits>
#include "level.hpp"
#include <Simpleton/ECS/registry.hpp>

class CompInits;

class LevelManager {
public:
  static constexpr Level NONE_LOADED = std::numeric_limits<Level>::max();
  static constexpr Level FINAL = NONE_LOADED - 1;

  LevelManager() = default;
  
  void init(ECS::Registry &, const CompInits &);
  void quit();
  
  bool loadLevel(Level);
  bool loadFinalLevel();
  bool nextLevel();
  bool reload();
  Level getLoaded() const;
  bool isLoaded() const;

private:
  ECS::Registry *registry = nullptr;
  const CompInits *compInits = nullptr;
  Level current = NONE_LOADED;
};

#endif
