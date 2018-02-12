//
//  start menu screen.cpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "start menu screen.hpp"

#include "game screen.hpp"
#include <SDL2/SDL_events.h>
#include "screen manager.hpp"
#include "rendering system.hpp"
#include "animation system.hpp"
#include "transform component.hpp"
#include "animation component.hpp"
#include "anim sprite rendering component.hpp"

void StartMenuScreen::init(RenderingSystem &renderingSystem) {
  rendering = &renderingSystem;

  const glm::vec2 scale = {16.0f / 9.0f, 1.0f};

  camera.setPos(scale / 2.0f);
  camera.transform.setOrigin(Cam2D::Origin::CENTER);
  zoomToFit.setSize(scale);
  
  const ECS::EntityID entity = registry.create();
  Animation &anim = registry.assign<Animation>(entity);
  anim.speed = 30.0f / 96.0f;
  AnimSpriteRendering &sprite = registry.assign<AnimSpriteRendering>(entity);
  sprite.sprite = rendering->getSheet().getIDfromName("title screen 0");
  sprite.frames = 96;
  Transform &transform = registry.assign<Transform>(entity);
  transform.scale = scale;
  
  rendering->onLevelLoad(registry);
}

void StartMenuScreen::quit() {
  registry.reset();
}

void StartMenuScreen::input(const SDL_Event &e) {
  if (e.type == SDL_KEYDOWN) {
    startGame = true;
  }
}

void StartMenuScreen::update(const float) {}

void StartMenuScreen::render(const float aspect, const float delta) {
  camera.animateProps(
    camera.calcTargetProps({aspect, delta}, zoomToFit),
    {aspect, delta}
  );
  const glm::mat3 viewProj = camera.transform.toPixels();
  
  animationSystem(registry, delta);
  rendering->render(registry, viewProj);
  
  if (startGame) {
    getScreenMan()->transitionTo<GameScreen>();
    startGame = false;
  }
}
