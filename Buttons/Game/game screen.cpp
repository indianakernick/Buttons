//
//  game screen.cpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "game screen.hpp"

#include "systems.hpp"
#include "yaml helper.hpp"
#include "render grid.hpp"
#include "global flags.hpp"
#include "entity id map.hpp"
#include <SDL2/SDL_events.h>
#include "screen manager.hpp"
#include "component inits.hpp"
#include "camera constants.hpp"
#include "rendering context.hpp"
#include <Simpleton/Utils/member function.hpp>
#include <Simpleton/Camera 2D/zoom to fit.hpp>
#include <Simpleton/Camera 2D/constant speed.hpp>

namespace {
  bool keyDown(const SDL_Event &e, const SDL_Scancode scancode) {
    return e.type == SDL_KEYDOWN && e.key.repeat == 0 && e.key.keysym.scancode == scancode;
  }
  bool keyUp(const SDL_Event &e, const SDL_Scancode scancode) {
    return e.type == SDL_KEYUP && e.key.keysym.scancode == scancode;
  }
}

void GameScreen::enter() {
  levels.reload();
  camera.setZoom(1.0f);
}

void GameScreen::init(RenderingContext &renderingContext) {
  camera.transform.setInvertY(true);
  camera.transform.setOrigin(Cam2D::Origin::CENTER);
  camera.targetZoom = std::make_unique<Cam2D::ZoomToFit>(LEVEL_SIZE);
  camera.animateZoom = std::make_unique<Cam2D::ZoomConstantSpeed>(ZOOM_SPEED);

  physics.init(registry, renderingContext.getContext());
  
  compInits.construct<PhysicsBodyInit>(physics.getWorld());
  compInits.construct<PhysicsJointInit>(physics.getWorld(), &registry);
  compInits.construct<PhysicsRayCastInit>();
  compInits.construct<PowerInputInit>();
  compInits.construct<MultiPowerInputInit>();
  compInits.construct<ActivationInit>();
  compInits.construct<TransformInit>();
  compInits.construct<AnimationInit>();
  compInits.construct<MovingPlatformInit>();
  compInits.construct<LaserDetectorInit>();
  compInits.construct<TextRenderingInit>(renderingContext.getResources());
  compInits.construct<TextInit>();
  compInits.construct<KeyInit>();
  compInits.construct<LockInit>();
  compInits.setDefaults();
  
  levels.init(registry, compInits);
  if (!levels.loadLevel(progress.getIncompleteLevel())) {
    //Player has pressed play but finished the game
  }
  
  inputDispatcher.addListener(Utils::memFun(this, &GameScreen::reloadKey));
  inputDispatcher.addListener(Utils::memFun(this, &GameScreen::quitKey));
  inputDispatcher.addListener(Utils::memFun(this, &GameScreen::playerInputKey));
  inputDispatcher.addListener(Utils::memFun(this, &GameScreen::toggleGotoLevelKey));
  inputDispatcher.addListener(Utils::memFun(this, &GameScreen::typeLevelNumberKey));
  inputDispatcher.addListener(Utils::memFun(this, &GameScreen::nextLevelKey));
  inputDispatcher.addListener(Utils::memFun(this, &GameScreen::prevLevelKey));
  inputDispatcher.addListener(Utils::memFun(this, &GameScreen::infoKey));
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
    if (levels.nextLevel()) {
      camera.setZoom(1.0f);
    } else {
      /* Player just finished the last level */
    }
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

void GameScreen::render(NVGcontext *const ctx, const float delta) {
  if constexpr (ENABLE_DEBUG_PHYSICS_RENDER) {
    physics.render();
  }
  
  if constexpr (ENABLE_GAME_RENDER) {
    animationSystem(registry, delta);
    movingPlatformRenderingSystem(registry, ctx);
    platformRenderingSystem(registry, ctx);
    laserEmitterRenderingSystem(registry, ctx);
    laserDetectorRenderingSystem(registry, ctx);
    buttonRenderingSystem(registry, ctx);
    boxRenderingSystem(registry, ctx);
    exitRenderingSystem(registry, ctx);
    keyRenderingSystem(registry, ctx);
    lockRenderingSystem(registry, ctx);
    playerRenderingSystem(registry, ctx);
    switchRenderingSystem(registry, ctx);
    doorRenderingSystem(registry, ctx);
    textRenderingSystem(registry, ctx);
    shadowRenderingSystem(registry, ctx);
  }
  
  if constexpr (ENABLE_GRID_RENDER) {
    renderGrid(ctx);
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
  if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
    if (!choosingLevel) {
      return false;
    }
    const SDL_Scancode code = e.key.keysym.scancode;
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
      camera.setZoom(1.0f);
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
        camera.setZoom(1.0f);
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
  const EntityID entity = registry.create();
  registry.assign<Text>(entity, message);
  Transform &transform = registry.assign<Transform>(entity);
  transform.pos = {0.0f, 8.0f};
  transform.scale = {0.05f, 0.05f};
  TextRendering &textRendering = registry.assign<TextRendering>(entity);
  YAML::Node renderingNode(YAML::NodeType::Map);
  renderingNode["font"] = "Arial.ttf";
  renderingNode["color"] = YAML::Node(YAML::NodeType::Sequence);
  renderingNode["color"].push_back(1.0f);
  renderingNode["color"].push_back(0.0f);
  renderingNode["color"].push_back(0.0f);
  renderingNode["hori align"] = "center";
  renderingNode["vert align"] = "middle";
  renderingNode["size"] = "24";
  compInits.init(textRendering, renderingNode, EntityIDmap(), entity);
}

