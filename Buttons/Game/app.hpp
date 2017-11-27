//
//  app.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef app_hpp
#define app_hpp

#include "screenshot.hpp"
#include "screen manager.hpp"
#include "rendering context.hpp"
#include <experimental/optional>
#include <Simpleton/Platform/window library.hpp>

class App {
public:
  using Duration = std::chrono::duration<float>;
  using Rep = typename Duration::rep;

  App() = default;
  
  void mainloop();

private:
  std::experimental::optional<Platform::WindowLibrary> windowLibrary;
  Platform::Window window;
  RenderingContext renderingContext;
  Screenshot screenshot;
  ScreenManager screens;
  
  void init();
  void quit();
  bool input(float);
  bool update(float);
  bool render(float);
};

#endif
