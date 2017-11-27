//
//  start menu screen.hpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef start_menu_screen_hpp
#define start_menu_screen_hpp

#include "screen.hpp"
#include "button element.hpp"
#include "input dispatcher.hpp"
#include "rendering resources.hpp"
#include <Simpleton/Camera 2D/camera.hpp>

class RenderingContext;
extern "C" union SDL_Event;

class StartMenuScreen final : public Screen {
public:
  StartMenuScreen() = default;
  
  void enter() override;
  void leave() override;
  
  void init(RenderingContext &) override;
  void quit() override;
  void input(const SDL_Event &) override;
  void update(float) override;
  glm::mat3 preRender(glm::ivec2, float) override;
  void render(NVGcontext *, float) override;

private:
  InputDispatcher inputDispatcher;
  Cam2D::Camera camera;
  FontHandle font;
  ButtonElement startButton;
};

#endif
