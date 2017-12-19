//
//  game screen.cpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "game screen.hpp"

#include "systems.hpp"
#include "json helper.hpp"
#include "render grid.hpp"
#include "event helper.hpp"
#include "global flags.hpp"
#include <SDL2/SDL_render.h>
#include "entity id map.hpp"
#include "screen manager.hpp"
#include "component inits.hpp"
#include "camera constants.hpp"
#include "rendering context.hpp"
#include <Simpleton/Platform/system info.hpp>
#include <Simpleton/Utils/member function.hpp>
#include <Simpleton/Camera 2D/zoom to fit.hpp>
#include <Simpleton/Camera 2D/constant speed.hpp>

void GameScreen::enter() {
  levels.reload();
  camera.setZoom(0.0f);
}

void GameScreen::init(RenderingContext &renderingContext) {
  camera.transform.setInvertY(true);
  camera.transform.setPosOrigin(Cam2D::Origin::BOTTOM_LEFT);
  camera.transform.setPosOriginSize(LEVEL_SIZE);
  camera.transform.setZoomOrigin(Cam2D::Origin::CENTER);
  camera.targetZoom = std::make_unique<Cam2D::ZoomToFit>(LEVEL_SIZE);
  camera.animateZoom = std::make_unique<Cam2D::ZoomConstantSpeed>(ZOOM_SPEED);

  physics.init(registry);
  rendering.init();
  
  compInits.construct<PhysicsBodyInit>(physics.getWorld());
  compInits.construct<PhysicsJointInit>(physics.getWorld(), &registry);
  compInits.construct<PhysicsRayCastInit>();
  compInits.construct<PowerInputInit>();
  compInits.construct<ActivationInit>();
  compInits.construct<TransformInit>();
  compInits.construct<AnimationInit>();
  compInits.construct<MovingPlatformInit>();
  compInits.construct<LaserDetectorInit>();
  compInits.construct<TextInit>();
  compInits.construct<KeyInit>();
  compInits.construct<LockInit>();
  compInits.setDefaults();
  
  levels.init(registry, compInits);
  if (!levels.loadLevel(progress.getIncompleteLevel())) {
    //Player has pressed play but finished the game
  }
  
  addListener(&GameScreen::reloadKey);
  addListener(&GameScreen::quitKey);
  addListener(&GameScreen::playerInputKey);
  addListener(&GameScreen::toggleGotoLevelKey);
  addListener(&GameScreen::typeLevelNumberKey);
  addListener(&GameScreen::nextLevelKey);
  addListener(&GameScreen::prevLevelKey);
  addListener(&GameScreen::infoKey);
}

void GameScreen::quit() {
  inputDispatcher.clearListeners();
  
  registry.reset();
  levels.quit();
  
  compInits.destroyAll();
  
  physics.quit();
}

void GameScreen::input(const SDL_Event &event) {
  inputDispatcher.dispatch(event);
}

void GameScreen::update(const float delta) {
  if (exitSystem(registry)) {
    progress.finishLevel(levels.getLoaded());
    levels.nextLevel();
    camera.setZoom(0.0f);
  }

  playerMovementSystem(registry, delta);
  physics.update(delta);
  physicsTransformSystem(registry);
  takeKeySystem(registry);
  activateLockSystem(registry);
  
  laserDetectorSystem(registry);
  activationSystem(registry, delta);
  doorSystem(registry);
  movingPlatformSystem(registry, delta);
  
  //Set outputs
  activatePowerOutputSystem(registry);
  buttonSystem(registry);
  switchSystem(registry);
  
  //Set inputs
  powerSystem(registry);
  
  //Respond to inputs
  powerInputActivationSystem(registry);
}

glm::mat3 GameScreen::preRender(const glm::ivec2 windowSize, const float delta) {
  camera.update(windowSize, delta);
  return camera.transform.toPixels();
}

class StartMenuScreen;

void GameScreen::render(SDL_Renderer *const renderer, const float delta) {
  if constexpr (ENABLE_DEBUG_PHYSICS_RENDER) {
    physics.render();
  }
  
  if constexpr (ENABLE_GAME_RENDER) {
    animationSystem(registry, delta);
    //activeSpriteRenderingSystem(registry, renderer, texture, sheet, camera.transform.toPixels());
  }
  
  if constexpr (ENABLE_GRID_RENDER) {
    renderGrid(renderer);
  }
  
  if (quitGame) {
    getScreenMan()->transitionTo<StartMenuScreen>();
    quitGame = false;
  }
}

void GameScreen::resetProgress() {
  progress.reset();
  levels.loadLevel(0);
}

template <typename Listener>
void GameScreen::addListener(const Listener listener) {
  inputDispatcher.addListener(Utils::memFun(this, listener));
}

bool GameScreen::reloadKey(const SDL_Event &e) {
  if (keyDown(e, SDL_SCANCODE_R)) {
    levels.reload();
    return true;
  }
  return false;
}

bool GameScreen::quitKey(const SDL_Event &e) {
  if (keyDown(e, SDL_SCANCODE_Q)) {
    quitGame = true;
    return true;
  }
  return false;
}

bool GameScreen::playerInputKey(const SDL_Event &e) {
  return playerInputSystem(registry, e);
}

bool GameScreen::toggleGotoLevelKey(const SDL_Event &e) {
  if (keyDown(e, SDL_SCANCODE_L)) {
    choosingLevel = true;
    return true;
  } else if (keyUp(e, SDL_SCANCODE_L)) {
    choosingLevel = false;
    if (!enteredLevel.empty()) {
      if (progress.hasCompleted(enteredLevel.get())) {
        levels.loadLevel(enteredLevel.get());
      } else {
        //Tell the player that the level they entered is not available
      }
    }
    enteredLevel.clear();
    return true;
  }
  return false;
}

bool GameScreen::typeLevelNumberKey(const SDL_Event &e) {
  if (keyDown(e)) {
    if (!choosingLevel) {
      return false;
    }
    const SDL_Scancode code = keyCode(e);
    //Why did they put SDL_SCANCODE_0 after SDL_SCANCODE_9?
    if (SDL_SCANCODE_1 <= code && code <= SDL_SCANCODE_9) {
      enteredLevel.push(code - SDL_SCANCODE_1 + 1);
      return true;
    } else if (code == SDL_SCANCODE_0) {
      enteredLevel.push(0);
      return true;
    }
  }
  return false;
}

bool GameScreen::nextLevelKey(const SDL_Event &e) {
  if (keyDown(e, SDL_SCANCODE_N)) {
    const Level current = levels.getLoaded();
    if (current == LevelManager::NONE_LOADED) {
      levels.loadLevel(0);
      camera.setZoom(0.0f);
    } else if (progress.hasCompleted(current + 1)) {
      levels.loadLevel(current + 1);
    }
    return true;
  }
  return false;
}

bool GameScreen::prevLevelKey(const SDL_Event &e) {
  if (keyDown(e, SDL_SCANCODE_B)) {
    const Level current = levels.getLoaded();
    if (current == LevelManager::NONE_LOADED) {
      // progress.getIncompleteLevel() returns the total number of levels when
      // the game has been completed. levels.loadLevel will return false if it
      // fails to load the level
      if (!levels.loadLevel(progress.getIncompleteLevel())) {
        levels.loadLevel(progress.getIncompleteLevel() - 1);
        camera.setZoom(0.0f);
      }
    } else if (current != 0) {
      levels.loadLevel(current - 1);
    }
    return true;
  }
  return false;
}

bool GameScreen::infoKey(const SDL_Event &e) {
  if (keyDown(e, SDL_SCANCODE_I)) {
    if (levels.isLoaded()) {
      printMessage("This is level " + std::to_string(levels.getLoaded()));
    }
    return true;
  }
  return false;
}

void GameScreen::printMessage(const std::string &message) {
  
}

