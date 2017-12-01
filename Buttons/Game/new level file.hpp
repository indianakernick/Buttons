//
//  new level file.hpp
//  Buttons
//
//  Created by Indi Kernick on 2/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef new_level_file_hpp
#define new_level_file_hpp

#include <string>
#include "entity registry.hpp"

class CompInits;

bool loadLevelJSON(const std::string &, Registry &, const CompInits &);


#endif
