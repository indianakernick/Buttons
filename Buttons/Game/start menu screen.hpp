//
//  start menu screen.hpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef start_menu_screen_hpp
#define start_menu_screen_hpp

#include "input dispatcher.hpp"
#include "rendering resources.hpp"
#include <Simpleton/Camera 2D/camera.hpp>

class RenderingContext;
extern "C" union SDL_Event;

class StartMenuScreen {
public:
  StartMenuScreen() = default;
  
  void enter();
  void leave();
  
  void init(RenderingContext &);
  void quit();
  void input(const SDL_Event &);
  void update(float);
  glm::mat3 preRender(glm::ivec2, float);
  void render(NVGcontext *, float);

private:
  InputDispatcher inputDispatcher;
  Cam2D::Camera camera;
  FontHandle font;
};

#endif
