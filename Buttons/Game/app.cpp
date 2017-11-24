//
//  app.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "app.hpp"

#include "systems.hpp"
#include "level file.hpp"
#include "global flags.hpp"
#include "component inits.hpp"
#include "window constants.hpp"
#include "camera constants.hpp"
#include <Simpleton/Time/get.hpp>
#include <Simpleton/Camera 2D/linear zoom.hpp>
#include <Simpleton/Camera 2D/zoom to fit.hpp>

void App::mainloop() {
  init();
  
  //Time::Mainloop::fixedWithVarPrePost isn't perfect
  
  //the application cannot control the mainloop properly so I'll have to
  //find another way of implementing the interface to Time::Mainloop
  
  static const float step = 1.0f/60.0f;
  static const uint32_t maxSteps = 16;
  
  Rep lag = 0;
  Time::Point<Duration> last = Time::getPoint<Duration>();
  bool ok = true;

  while (ok) {
    const Time::Point<Duration> now = Time::getPoint<Duration>();
    const Duration elapsed = now - last;
    last = now;
    lag += elapsed.count();
    
    uint32_t numSteps = lag < 0 ? 0 : std::min(static_cast<uint32_t>(lag / step), maxSteps);
    const Rep stepSize = step * numSteps;
    lag -= stepSize;
    
    ok = input(stepSize);
    
    while (numSteps) {
      ok = ok && update(step);
      numSteps--;
    }
    
    ok = ok && render(stepSize);
  }
  
  quit();
}

void App::init() {
  windowLibrary.emplace(SDL_INIT_EVENTS);
  window = Platform::makeWindow(WINDOW_DESC);
  renderingContext.init(window.get());
  renderingManager.init(renderingContext);
  camera.targetScale = std::make_unique<Cam2D::ZoomToFit>(LEVEL_SIZE);
  camera.zoom = std::make_unique<Cam2D::LinearZoom>(ZOOM_SPEED);
  
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
  compInits.setDefaults();
  
  levelManager.init(registry, compInits);
  levelManager.loadLevel(0);
}

void App::quit() {
  registry.reset();
  levelManager.quit();
  
  compInits.destroyAll();

  physics.quit();

  renderingManager.quit();
  renderingContext.quit();
  window.reset();
  windowLibrary = std::experimental::nullopt;
}

bool App::input(float) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      return false;
    } else if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_R) {
      levelManager.reload();
    } else if (!screenshot.handleEvent(e)) {
      playerInputSystem(registry, e);
    }
  }
  return true;
}

bool App::update(const float delta) {
  if (exitSystem(registry)) {
    if (levelManager.nextLevel()) {
      camera.setScale(1.0f);
    } else {
      /* Player just finished the last level */
    }
  }

  playerMovementSystem(registry, delta);
  physics.update(delta);
  physicsTransformSystem(registry);
  
  laserDetectorSystem(registry);
  activationSystem(registry, delta);
  doorSystem(registry);
  movingPlatformSystem(registry, delta);
  
  //Set outputs
  activatePowerOutputSystem(registry);
  buttonSystem(registry);
  switchSystem(registry);
  inverterSystem(registry);
  //Set inputs
  powerSystem(registry);
  //Respond to inputs
  powerInputActivationSystem(registry);
  
  return true;
}

bool App::render(const float delta) {
  camera.update(window.size(), delta);
  renderingContext.preRender(camera.transform.toPixels());
  
  if constexpr (ENABLE_DEBUG_PHYSICS_RENDER) {
    physics.render();
  }
  
  if constexpr (ENABLE_GAME_RENDER) {
    animationSystem(registry, delta);
  
    NVGcontext *const ctx = renderingContext.getContext();
    movingPlatformRenderingSystem(registry, ctx);
    platformRenderingSystem(registry, ctx);
    laserEmitterRenderingSystem(registry, ctx);
    laserDetectorRenderingSystem(registry, ctx);
    buttonRenderingSystem(registry, ctx);
    boxRenderingSystem(registry, ctx);
    exitRenderingSystem(registry, ctx);
    playerRenderingSystem(registry, ctx);
    switchRenderingSystem(registry, ctx);
    doorRenderingSystem(registry, ctx);
    textRenderingSystem(registry, ctx);
  }
  
  renderingManager.render();
  screenshot.postRender(renderingContext, ENABLE_FPS_RENDER);
  return true;
}
