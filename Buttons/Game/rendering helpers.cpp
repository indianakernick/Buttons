//
//  rendering helpers.cpp
//  Buttons
//
//  Created by Indi Kernick on 22/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "rendering helpers.hpp"

namespace {
  glm::vec2 getSheetSize(const Spritesheet &sheet) {
    const Unpack::VecPx size = sheet.getSize();
    return {size.x, size.y};
  }
}

TexCoords lookupTexCoords(const Spritesheet &sheet, const SpriteID sprite) {
  const glm::vec2 sheetSize = getSheetSize(sheet);
  const Unpack::RectPx rect = sheet.getSprite(sprite);
  TexCoords coords;
  coords.bottomLeft = glm::vec2(rect.x, rect.y) / sheetSize;
  coords.topRight = coords.bottomLeft + glm::vec2(rect.w, rect.h) / sheetSize;
  return coords;
}

glm::vec3 mulPos(const glm::mat3 &mat, const glm::vec2 pos, const float depth) {
  const glm::vec3 newPos = mat * glm::vec3(pos.x, pos.y, 1.0f);
  return {newPos.x, newPos.y, depth};
}

SpriteID getAnimFrame(const float prog, const SpriteID start, const SpriteID count) {
  return start + 0.9999f * prog * count;
}

void setTexCoords(Quad &quad, const TexCoords coords) {
  quad[0].texCoord = {coords.bottomLeft.x, coords.topRight.y};
  quad[1].texCoord = coords.topRight;
  quad[2].texCoord = {coords.topRight.x, coords.bottomLeft.y};
  quad[3].texCoord = coords.bottomLeft;
}
