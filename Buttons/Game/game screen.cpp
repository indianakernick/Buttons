//
//  game screen.cpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "game screen.hpp"

#include "systems.hpp"
#include "render grid.hpp"
#include "global flags.hpp"
#include <SDL2/SDL_events.h>
#include "component inits.hpp"
#include "camera constants.hpp"
#include "rendering context.hpp"
#include <Simpleton/Camera 2D/zoom to fit.hpp>
#include <Simpleton/Camera 2D/constant speed.hpp>

void GameScreen::enter() {
  levelManager.reload();
  camera.setZoom(1.0f);
}

void GameScreen::leave() {
  
}

void GameScreen::init(RenderingContext &renderingContext) {
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
  
  levelManager.init(registry, compInits);
  levelManager.loadLevel(0);
  
  inputDispatcher.addListener([this] (const SDL_Event &e) {
    if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_R) {
      levelManager.reload();
      return true;
    } else {
      return false;
    }
  });
  inputDispatcher.addListener([this] (const SDL_Event &e) {
    return playerInputSystem(registry, e);
  });
}

void GameScreen::quit() {
  inputDispatcher.clearListeners();
  
  registry.reset();
  levelManager.quit();
  
  compInits.destroyAll();
  
  physics.quit();
}

void GameScreen::input(const SDL_Event event) {
  inputDispatcher.dispatch(event);
}

void GameScreen::update(const float delta) {
  if (exitSystem(registry)) {
    if (levelManager.nextLevel()) {
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
}
