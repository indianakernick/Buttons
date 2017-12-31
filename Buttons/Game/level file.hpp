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
#include "component list.hpp"
#include <Simpleton/ECS/registry.hpp>
#include <Simpleton/ECS/comp inits.hpp>

bool loadLevel(const std::string &, const ECS::CompInits<CompList> &, ECS::Registry &);

#endif
