//
//  main.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "app.hpp"

#include <Simpleton/SDL/mainloop.hpp>
#include <Simpleton/Utils/profiler.hpp>

int main(int, char **) {
  App app;
  SDL::runMainloop(&app);
  PROFILER_INFO(stdout);
  return 0;
}
