//
//  dir.cpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "dir.hpp"

#include <Simpleton/Platform/system info.hpp>

std::string getSaveDir() {
  return Platform::getSaveDir("Indi Kernick", "Buttons");
}

std::string getResDir() {
  return Platform::getResDir();
}
