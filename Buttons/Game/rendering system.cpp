//
//  rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 19/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "rendering system.hpp"

#include <Simpleton/OpenGL/uniforms.hpp>
#include <Simpleton/Platform/system info.hpp>
#include <Simpleton/OpenGL/attrib pointer.hpp>

void RenderingSystem::init() {
  const std::string path = Platform::getResDir() + "sprites.";
  sheet = Unpack::makeSpritesheet(path + "atlas", path + "png");
  const Unpack::Image &image = sheet.getImage();
  const GL::Image2D glImage = {image.data(), image.width(), image.height()};
  GL::TexParams2D texParams;
  texParams.setWrap(GL_CLAMP);
  texParams.setFilter(GL_NEAREST);
  texture = GL::makeTexture2D(glImage, texParams);
}

void RenderingSystem::quit() {
  texture = nullptr;
}
