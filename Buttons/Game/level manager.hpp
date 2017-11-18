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
#include "entity registry.hpp"

class LevelManager {
public:
  LevelManager() = default;
  
  void init(Registry &);
  void quit();
  
  void loadLevel(unsigned);
  bool nextLevel();
  void reload();

private:
  static constexpr unsigned NONE_LOADED = std::numeric_limits<unsigned>::max();
  
  Registry *registry = nullptr;
  unsigned current = NONE_LOADED;
};

#endif
