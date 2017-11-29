//
//  progress manager.hpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef progress_manager_hpp
#define progress_manager_hpp

#include <fstream>
#include "level.hpp"

class ProgressManager {
public:
  ProgressManager();
  ~ProgressManager();
  
  Level getIncompleteLevel() const;
  bool hasCompleted(Level) const;
  void finishLevel(Level);
  void reset();
  
private:
  Level numCompleted;
};

#endif
