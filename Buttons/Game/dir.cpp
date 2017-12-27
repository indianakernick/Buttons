//
//  dir.cpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "dir.hpp"

#include <Simpleton/SDL/paths.hpp>

std::string getSaveDir() {
  return SDL::getSaveDir("Indi Kernick", "Buttons");
}

