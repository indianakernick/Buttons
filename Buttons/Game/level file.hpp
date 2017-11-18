//
//  level file.hpp
//  Buttons
//
//  Created by Indi Kernick on 10/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef level_file_hpp
#define level_file_hpp

#include <string>
#include "entity registry.hpp"

class CompInits;

void loadLevel(const std::string &, Registry &, const CompInits &);

#endif
