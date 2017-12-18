//
//  active sprite rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "active sprite rendering system.hpp"

#include <SDL2/SDL_render.h>
#include <glm/trigonometric.hpp>
#include "transform component.hpp"
#include "activation component.hpp"
#include "active sprite rendering component.hpp"

/*
@TODO OpenGL

This is just temporary. OpenGL supports matricies and batch rendering
*/

namespace {
  using Unpack::SpriteID;

  SpriteID calcSprite(const float progress, const SpriteID begin, const SpriteID size) {
    return begin + static_cast<SpriteID>(std::round(progress * size));
  }
  
  SDL_Rect toSDL(const Unpack::RectPx rect) {
    return {rect.x, rect.y, rect.w, rect.h};
  }
  
  SDL_Rect toRect(const glm::mat3 mat) {
    glm::ivec2 pos = mat * glm::vec3(0.0f, 0.0f, 1.0f);
    glm::ivec2 size = mat * glm::vec3(1.0f, 1.0f, 0.0f);
    if (size.x < 0) {
      pos += size.x;
      size.x = -size.x;
    }
    if (size.y < 0) {
      pos += size.y;
      size.y = -size.y;
    }
    return {pos.x, pos.y, size.x, size.y};
  }
}

void activeSpriteRenderingSystem(
  Registry &registry,
  SDL_Renderer *const renderer,
  SDL_Texture *const texture,
  Unpack::Spritesheet &sheet,
  const glm::mat3 camera
) {
  const auto view = registry.view<Transform, Activation, ActiveSpriteRendering>();
  
  for (EntityID entity : view) {
    const float activity = view.get<Activation>(entity).activity;
    const ActiveSpriteRendering rendering = view.get<ActiveSpriteRendering>(entity);
    const SpriteID sprite = calcSprite(activity, rendering.sprite, rendering.numFrames);
    Transform transform = view.get<Transform>(entity);
    
    const SDL_Rect srcrect = toSDL(sheet.getSprite(sprite));
    const double angle = -glm::degrees(transform.rotation);
    transform.rotation = 0.0f;
    const SDL_Rect dstrect = toRect(camera * getMat3(transform));
    const SDL_Point center = {0, 0};
    
    SDL_RenderCopyEx(renderer, texture, &srcrect, &dstrect, angle, &center, SDL_FLIP_NONE);
  }
}
