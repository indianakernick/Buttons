//
//  static sprite rendering init.cpp
//  Buttons
//
//  Created by Indi Kernick on 21/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "static sprite rendering init.hpp"

StaticSpriteRenderingInit::StaticSpriteRenderingInit(const Unpack::Spritesheet &sheet)
  : sheet(sheet) {}

void StaticSpriteRenderingInit::init(StaticSpriteRendering &comp, const json &node) {
  const std::string &spriteName = node.at("sprite").get_ref<const std::string &>();
  comp.sprite = sheet.getIDfromName(spriteName);
  getOptional(comp.offset, node, "offset");
}
