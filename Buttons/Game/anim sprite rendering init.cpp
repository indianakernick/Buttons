//
//  anim sprite rendering init.cpp
//  Buttons
//
//  Created by Indi Kernick on 21/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "anim sprite rendering init.hpp"

AnimSpriteRenderingInit::AnimSpriteRenderingInit(const Unpack::Spritesheet &sheet)
  : sheet(sheet) {}

void AnimSpriteRenderingInit::init(AnimSpriteRendering &comp, const json &node) {
  const std::string &spriteName = node.at("sprite").get_ref<const std::string &>();
  comp.sprite = sheet.getIDfromName(spriteName);
  if (comp.sprite == Unpack::NULL_SPRITE) {
    throw std::runtime_error("Invalid sprite name");
  }
  comp.frames = node.at("frames").get<Unpack::SpriteID>();
}
