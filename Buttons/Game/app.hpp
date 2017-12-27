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
  using Duration = std::chrono::duration<float>;
  using Rep = typename Duration::rep;

  App() = default;
  
  void mainloop();

private:
  SDL::Library windowLibrary;
  SDL::Window window;
  RenderingContext renderingContext;
  ScreenManager screens;
  RenderingSystem renderingSystem;
  
  void init();
  void quit();
  bool input(float);
  bool update(float);
  bool render(float);
};

#endif
