//
//  text rendering init.cpp
//  Buttons
//
//  Created by Indi Kernick on 22/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "text rendering init.hpp"

TextRenderingInit::TextRenderingInit(const Unpack::Spritesheet &sheet)
  : sheet(sheet) {}

void TextRenderingInit::init(TextRendering &comp, const json &node) {
  const std::string &spriteName = node.at("sprite").get_ref<const std::string &>();
  comp.sprite = sheet.getIDfromName(spriteName);
  if (comp.sprite == Unpack::NULL_SPRITE) {
    throw std::runtime_error("Invalid sprite name");
  }
  comp.depth = node.at("depth").get<float>();
  comp.scale = node.at("scale").get<glm::vec2>();
  comp.kern = node.at("kern").get<float>();
}
