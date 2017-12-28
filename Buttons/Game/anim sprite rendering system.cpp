//
//  anim sprite rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 22/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "anim sprite rendering system.hpp"

#include "transform component.hpp"
#include "animation component.hpp"
#include "anim sprite rendering component.hpp"

size_t countAnimSprites(ECS::Registry &registry) {
  return registry.view<AnimSpriteRendering>().size();
}

void writeAnimSprites(
  ECS::Registry &registry,
  const Spritesheet &sheet,
  QuadIter &quadIter
) {
  const auto view = registry.view<AnimSpriteRendering, Animation, Transform>();
  
  for (const ECS::EntityID entity : view) {
    Quad &quad = *quadIter;
    
    const float progress = view.get<Animation>(entity).progress;
    const AnimSpriteRendering anim = view.get<AnimSpriteRendering>(entity);
    const SpriteID frame = getAnimFrame(progress, anim.sprite, anim.frames);
    const glm::mat3 world = getMat3(view.get<Transform>(entity));
    
    for (size_t v = 0; v != 4; ++v) {
      quad[v].pos = mulPos(world, anim.offset + anim.scale * CORNER[v], anim.depth);
    }
    
    setTexCoords(quad, lookupTexCoords(sheet, frame));
    
    ++quadIter;
  }
}
