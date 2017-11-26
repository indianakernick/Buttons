//
//  game screen.hpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef game_screen_hpp
#define game_screen_hpp

#include "comp inits.hpp"
#include "level manager.hpp"
#include "physics system.hpp"
#include "entity registry.hpp"
#include "input dispatcher.hpp"
#include "progress manager.hpp"
#include <Simpleton/Camera 2D/camera.hpp>

class RenderingContext;
extern "C" union SDL_Event;

class GameScreen {
public:
  GameScreen() = default;
  
  void enter();
  void leave();
  
  void init(RenderingContext &);
  void quit();
  void input(SDL_Event);
  void update(float);
  glm::mat3 preRender(glm::ivec2, float);
  void render(NVGcontext *, float);

private:
  Registry registry;
  PhysicsSystem physics;
  CompInits compInits;
  LevelManager levelManager;
  ProgressManager progressManager;
  InputDispatcher inputDispatcher;
  Cam2D::Camera camera;
};

#endif
