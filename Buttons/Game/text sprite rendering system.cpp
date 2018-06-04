//
//  text sprite rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 23/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "text sprite rendering system.hpp"

#include "text component.hpp"
#include "transform component.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/matrix_transform_2d.hpp>
#include "text rendering component.hpp"

size_t countTextSprites(ECS::Registry &registry) {
  const auto view = registry.view<Text>();
  size_t count = 0;
  for (const ECS::EntityID entity : view) {
    count += view.get(entity).indicies.size();
  }
  return count;
}

namespace {
  void writeTextSprite(
    const std::vector<uint8_t> &text,
    glm::mat3 world,
    const TextRendering &render,
    const Spritesheet &sheet,
    QuadIter &quadIter
  ) {
    const float glyphWidth = render.scale.x + render.kern;
    const glm::vec2 size = {
      glyphWidth * text.size() - render.kern,
      render.scale.y
    };
    static constexpr glm::mat3 I = {
      {1, 0, 0},
      {0, 1, 0},
      {0, 0, 1}
    };
    world = world * glm::translate(I, -size / 2.0f);
    
    for (size_t i = 0; i != text.size(); ++i) {
      const uint8_t glyph = text[i];
      Quad &quad = *quadIter;
      
      const glm::vec2 offset = {i * glyphWidth, 0.0f};
      for (size_t v = 0; v != 4; ++v) {
        quad[v].pos = mulPos(world, render.scale * CORNER[v] + offset, render.depth);
      }
      
      setTexCoords(quad, lookupTexCoords(sheet, render.sprite + glyph));
      
      ++quadIter;
    }
  }
}

void writeTextSprites(
  ECS::Registry &registry,
  const Spritesheet &sheet,
  QuadIter &quadIter
) {
  const auto view = registry.view<Text, TextRendering, Transform>();
  
  for (const ECS::EntityID entity : view) {
    writeTextSprite(
      view.get<Text>(entity).indicies,
      getMat3(view.get<Transform>(entity)),
      view.get<TextRendering>(entity),
      sheet,
      quadIter
    );
  }
}
