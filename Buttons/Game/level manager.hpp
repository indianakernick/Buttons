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
#include "entity registry.hpp"

class CompInits;

class LevelManager {
public:
  LevelManager() = default;
  
  void init(Registry &, const CompInits &);
  void quit();
  
  bool loadLevel(Level);
  bool nextLevel();
  bool reload();

private:
  static constexpr Level NONE_LOADED = std::numeric_limits<Level>::max();
  
  Registry *registry = nullptr;
  const CompInits *compInits = nullptr;
  Level current = NONE_LOADED;
};

#endif
