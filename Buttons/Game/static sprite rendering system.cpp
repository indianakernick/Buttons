//
//  static sprite rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 22/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "static sprite rendering system.hpp"

#include "transform component.hpp"
#include "static sprite rendering component.hpp"

size_t countStaticSprites(Registry &registry) {
  return registry.view<StaticSpriteRendering>().size();
}

void writeStaticSprites(
  Registry &registry,
  const Spritesheet &sheet,
  QuadIter quadIter
) {
  const auto view = registry.view<StaticSpriteRendering, Transform>();
  
  for (const EntityID entity : view) {
    Quad &quad = *quadIter;
    
    const StaticSpriteRendering sprite = view.get<StaticSpriteRendering>(entity);
    const glm::mat3 world = getMat3(view.get<Transform>(entity));
    const float depth = sprite.depth;
  
    for (size_t v = 0; v != 4; ++v) {
      quad[v].pos = mulPos(world, CORNER[v], depth);
    }
    setTexCoords(quad, lookupTexCoords(sheet, sprite.sprite));
    
    ++quadIter;
  }
}
