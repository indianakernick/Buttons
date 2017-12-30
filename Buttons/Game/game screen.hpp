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
#include "level manager.hpp"
#include "physics system.hpp"
#include "component list.hpp"
#include "input dispatcher.hpp"
#include <Simpleton/ECS/registry.hpp>
#include <Simpleton/ECS/comp inits.hpp>
#include <Simpleton/Math/digit stack.hpp>
#include <Simpleton/Camera 2D/camera.hpp>
#include <Simpleton/ECS/progress manager.hpp>

extern "C" union SDL_Event;

class GameScreen final : public Screen {
public:
  GameScreen() = default;
  
  void enter() override;
  
  void init(RenderingSystem &) override;
  void quit() override;
  void input(const SDL_Event &) override;
  void update(float) override;
  void render(float, float) override;
  
  void resetProgress();

private:
  ECS::Registry registry;
  PhysicsSystem physics;
  RenderingSystem *rendering;
  ECS::CompInits<CompList> compInits;
  LevelManager levels;
  ECS::ProgressManager progress;
  InputDispatcher inputDispatcher;
  Cam2D::Camera camera;
  
  Math::DigitStack<ECS::Level> enteredLevel;
  bool choosingLevel = false;
  bool quitGame = false;
  
  bool loadLevel(ECS::Level);
  bool loadFinalLevel();
  bool loadNextLevel();
  void reloadLevel();
  
  template <typename Listener>
  void addListener(Listener);
  
  bool reloadKey(const SDL_Event &);
  bool quitKey(const SDL_Event &);
  bool playerInputKey(const SDL_Event &);
  bool toggleGotoLevelKey(const SDL_Event &);
  bool typeLevelNumberKey(const SDL_Event &);
  bool nextLevelKey(const SDL_Event &);
  bool prevLevelKey(const SDL_Event &);
};

#endif
