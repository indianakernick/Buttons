//
//  game screen.cpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "game screen.hpp"

#include "systems.hpp"
#include "global flags.hpp"
#include "screen manager.hpp"
#include "component inits.hpp"
#include "camera constants.hpp"
#include "rendering system.hpp"
#include <Simpleton/SDL/paths.hpp>
#include <Simpleton/SDL/events.hpp>
#include <Simpleton/Utils/member function.hpp>
#include <Simpleton/Camera 2D/zoom to fit.hpp>
#include <Simpleton/Camera 2D/constant speed.hpp>

void GameScreen::enter() {
  reloadLevel();
}

void GameScreen::init(RenderingSystem &renderingSystem) {
  rendering = &renderingSystem;
  
  camera.setPos(LEVEL_SIZE / 2.0f);
  camera.transform.setOrigin(Cam2D::Origin::CENTER);
  camera.targetZoom = std::make_unique<Cam2D::ZoomToFit>(LEVEL_SIZE);
  camera.animateZoom = std::make_unique<Cam2D::ZoomConstantSpeed>(ZOOM_SPEED);

  physics.init(registry);
  
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
  compInits.construct<LaserRenderingInit>();
  compInits.construct<TextRenderingInit>(rendering->getSheet());
  compInits.construct<AnimSpriteRenderingInit>(rendering->getSheet());
  compInits.construct<StaticSpriteRenderingInit>(rendering->getSheet());
  compInits.constructDefaults();
  
  progress.setFilePath(SDL::getSaveDir("Indi Kernick", "Buttons") + "progress.txt");
  progress.readFile();
  levels.init(registry, compInits);
  levels.levelPath([] (const ECS::Level level) {
    const std::string levelStr = level == ECS::FINAL_LEVEL ? "final" : std::to_string(level);
    return SDL::getResDir() + "level " + levelStr + ".json";
  });
  if (!loadLevel(progress.getIncompleteLevel())) {
    loadFinalLevel();
  }
  
  addListener(&GameScreen::reloadKey);
  addListener(&GameScreen::quitKey);
  addListener(&GameScreen::playerInputKey);
  addListener(&GameScreen::toggleGotoLevelKey);
  addListener(&GameScreen::typeLevelNumberKey);
  addListener(&GameScreen::nextLevelKey);
  addListener(&GameScreen::prevLevelKey);
}

void GameScreen::quit() {
  inputDispatcher.clearListeners();
  
  registry.reset();
  levels.quit();
  
  compInits.destroyAll();
  
  physics.quit();
  
  rendering = nullptr;
}

void GameScreen::input(const SDL_Event &event) {
  inputDispatcher.dispatch(event);
}

void GameScreen::update(const float delta) {
  if (exitSystem(registry)) {
    progress.finishLevel(levels.getLoaded());
    loadNextLevel();
  }

  playerMovementSystem(registry, delta);
  physics.update(delta);
  physicsTransformSystem(registry);
  takeKeySystem(registry);
  activateLockSystem(registry);
  
  laserDetectorSystem(registry);
  activationSystem(registry, delta);
  activationAnimationSystem(registry);
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

class StartMenuScreen;

void GameScreen::render(const float aspect, const float delta) {
  camera.update(aspect, delta);
  const glm::mat3 viewProj = camera.transform.toPixels();
  if constexpr (ENABLE_DEBUG_PHYSICS_RENDER) {
    physics.render();
  }
  
  if constexpr (ENABLE_GAME_RENDER) {
    animationSystem(registry, delta);
    rendering->render(registry, viewProj);
  }
  
  if (quitGame) {
    getScreenMan()->transitionTo<StartMenuScreen>();
    quitGame = false;
  }
}

bool GameScreen::loadLevel(const ECS::Level level) {
  if (levels.loadLevel(level)) {
    camera.setZoom(0.0f);
    rendering->onLevelLoad(registry);
    return true;
  } else {
    return false;
  }
}

bool GameScreen::loadFinalLevel() {
  return loadLevel(ECS::FINAL_LEVEL);
}

bool GameScreen::loadNextLevel() {
  if (levels.nextLevel()) {
    camera.setZoom(0.0f);
    rendering->onLevelLoad(registry);
    return true;
  } else {
    return false;
  }
}

void GameScreen::reloadLevel() {
  levels.reload();
  rendering->onLevelLoad(registry);
}

template <typename Listener>
void GameScreen::addListener(const Listener listener) {
  inputDispatcher.addListener(Utils::memFun(this, listener));
}

bool GameScreen::reloadKey(const SDL_Event &e) {
  if (SDL::keyDown(e, SDL_SCANCODE_R)) {
    reloadLevel();
    return true;
  }
  return false;
}

bool GameScreen::quitKey(const SDL_Event &e) {
  if (SDL::keyDown(e, SDL_SCANCODE_Q)) {
    quitGame = true;
    return true;
  }
  return false;
}

bool GameScreen::playerInputKey(const SDL_Event &e) {
  return playerInputSystem(registry, e);
}

bool GameScreen::toggleGotoLevelKey(const SDL_Event &e) {
  if (SDL::keyDown(e, SDL_SCANCODE_L)) {
    choosingLevel = true;
    return true;
  } else if (SDL::keyUp(e, SDL_SCANCODE_L)) {
    choosingLevel = false;
    if (!enteredLevel.empty()) {
      if (progress.hasCompleted(enteredLevel.get())) {
        loadLevel(enteredLevel.get());
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
  if (SDL::keyDown(e)) {
    if (!choosingLevel) {
      return false;
    }
    const SDL_Scancode code = SDL::keyCode(e.key);
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
  if (SDL::keyDown(e, SDL_SCANCODE_N)) {
    const ECS::Level current = levels.getLoaded();
    if (current == ECS::NULL_LEVEL) {
      loadLevel(0);
    } else if (progress.hasCompleted(current + 1)) {
      loadLevel(current + 1);
    }
    return true;
  }
  return false;
}

bool GameScreen::prevLevelKey(const SDL_Event &e) {
  if (SDL::keyDown(e, SDL_SCANCODE_B)) {
    const ECS::Level current = levels.getLoaded();
    if (current == ECS::NULL_LEVEL) {
      // progress.getIncompleteLevel() returns the total number of levels when
      // the game has been completed. levels.loadLevel will return false if it
      // fails to load the level
      if (!loadLevel(progress.getIncompleteLevel())) {
        loadLevel(progress.getIncompleteLevel() - 1);
      }
    } else if (current != 0) {
      loadLevel(current - 1);
    }
    return true;
  }
  return false;
}

