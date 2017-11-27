//
//  game screen.hpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef game_screen_hpp
#define game_screen_hpp

#include "screen.hpp"
#include "comp inits.hpp"
#include "level manager.hpp"
#include "physics system.hpp"
#include "entity registry.hpp"
#include "input dispatcher.hpp"
#include "progress manager.hpp"
#include <Simpleton/Camera 2D/camera.hpp>

class RenderingContext;
extern "C" union SDL_Event;

class GameScreen final : public Screen {
public:
  GameScreen() = default;
  
  void enter() override;
  void leave() override;
  
  void init(RenderingContext &) override;
  void quit() override;
  void input(const SDL_Event &) override;
  void update(float) override;
  glm::mat3 preRender(glm::ivec2, float) override;
  void render(NVGcontext *, float) override;

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
