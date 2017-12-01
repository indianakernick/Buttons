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
#include <Simpleton/Math/digit stack.hpp>
#include <Simpleton/Camera 2D/camera.hpp>

class RenderingContext;
extern "C" union SDL_Event;

class GameScreen final : public Screen {
public:
  GameScreen() = default;
  
  void enter() override;
  
  void init(RenderingContext &) override;
  void quit() override;
  void input(const SDL_Event &) override;
  void update(float) override;
  glm::mat3 preRender(glm::ivec2, float) override;
  void render(NVGcontext *, float) override;
  
  void resetProgress();

private:
  Registry registry;
  PhysicsSystem physics;
  CompInits compInits;
  LevelManager levels;
  ProgressManager progress;
  InputDispatcher inputDispatcher;
  Cam2D::Camera camera;
  
  Math::DigitStack<Level> enteredLevel;
  bool choosingLevel = false;
  bool quitGame = false;
  
  bool reloadKey(const SDL_Event &);
  bool quitKey(const SDL_Event &);
  bool playerInputKey(const SDL_Event &);
  bool toggleGotoLevelKey(const SDL_Event &);
  bool typeLevelNumberKey(const SDL_Event &);
  bool nextLevelKey(const SDL_Event &);
  bool prevLevelKey(const SDL_Event &);
  bool infoKey(const SDL_Event &);
  
  void printMessage(const std::string &);
};

#endif
