//
//  app.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef app_hpp
#define app_hpp

#include <chrono>
#include "screen manager.hpp"
#include "rendering system.hpp"
#include "rendering context.hpp"
#include <Simpleton/SDL/library.hpp>

class App {
public:
  App() = default;
  
  bool mainloop(uint64_t);
  void init();
  void quit();

private:
  SDL::Library windowLibrary;
  SDL::Window window;
  RenderingContext renderingContext;
  ScreenManager screens;
  RenderingSystem renderingSystem;
  
  bool input(float);
  bool update(float);
  bool render(float);
};

#endif
