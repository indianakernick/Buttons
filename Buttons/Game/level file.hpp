//
//  level file.hpp
//  Buttons
//
//  Created by Indi Kernick on 2/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef level_file_hpp
#define level_file_hpp

#include <string>
#include "entity registry.hpp"

class CompInits;

bool loadLevel(const std::string &, const CompInits &, Registry &);


#endif
