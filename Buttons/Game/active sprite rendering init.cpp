//
//  active sprite rendering init.cpp
//  Buttons
//
//  Created by Indi Kernick on 18/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "active sprite rendering init.hpp"

#include <Unpacker/unpacker.hpp>

ActiveSpriteRenderingInit::ActiveSpriteRenderingInit(const Unpack::Spritesheet &sheet)
  : sheet(sheet) {}

void ActiveSpriteRenderingInit::init(ActiveSpriteRendering &comp, const json &node) {
  const std::string &spriteName = node.at("sprite").get_ref<const std::string &>();
  comp.sprite = sheet.getIDfromName(spriteName);
  comp.numFrames = node.at("frames").get<Unpack::SpriteID>();
}
