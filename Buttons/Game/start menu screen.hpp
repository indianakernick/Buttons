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
#include "element manager.hpp"
#include <Simpleton/Camera 2D/camera.hpp>

class RenderingContext;
extern "C" union SDL_Event;

class StartMenuScreen final : public Screen {
public:
  StartMenuScreen() = default;
  
  void init(RenderingContext &) override;
  void quit() override;
  void input(const SDL_Event &) override;
  void update(float) override;
  glm::mat3 preRender(glm::ivec2, float) override;
  void render(SDL_Renderer *, float) override;

private:
  Cam2D::Camera camera;
  ElementManager elementMan;
  bool startGame = false;
};

#endif
