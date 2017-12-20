//
//  rendering system.cpp
//  Buttons
//
//  Created by Indi Kernick on 19/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "rendering system.hpp"

#include <fstream>
#include "activation component.hpp"
#include <Simpleton/Platform/system info.hpp>
#include <Simpleton/OpenGL/attrib pointer.hpp>
#include "active sprite rendering component.hpp"

namespace {
  using PosType = glm::vec2;
  using TexCoordType = glm::vec2;
  using ElemType = unsigned short;
  
  constexpr GLint POS_ID = 0;
  constexpr GLint TEX_COORD_ID = 1;
  
  constexpr size_t QUAD_ATTR_SIZE = (sizeof(PosType) + sizeof(TexCoordType)) * 4;
  constexpr size_t QUAD_ELEM_SIZE = sizeof(ElemType) * 6;
  
  constexpr auto *enablePos = GL::enable<POS_ID, PosType>;
  constexpr auto *enableTexCoord = GL::enable<TEX_COORD_ID, TexCoordType>;
  
  constexpr auto *posPointer = GL::attribPointer<POS_ID, PosType>;
  constexpr auto *texCoordPointer = GL::attribPointer<TEX_COORD_ID, TexCoordType>;
}

void RenderingSystem::init() {
  const std::string path = Platform::getResDir() + "sprites.";
  sheet = Unpack::makeSpritesheet(path + "atlas", path + "png");
  const Unpack::Image &image = sheet.getImage();
  const GL::Image2D glImage = {image.data(), image.width(), image.height()};
  GL::TexParams2D texParams;
  texParams.setWrap(GL_CLAMP_TO_EDGE);
  texParams.setFilter(GL_NEAREST);
  glActiveTexture(GL_TEXTURE0);
  texture = GL::makeTexture2D(glImage, texParams);
  vertArray = GL::makeVertexArray();
  
  std::ifstream vertFile(Platform::getResDir() + "sprite shader.vert");
  assert(vertFile.is_open());
  std::ifstream fragFile(Platform::getResDir() + "sprite shader.frag");
  assert(fragFile.is_open());
  
  std::cout << "Creating vertex shader\n";
  GL::Shader vertShader = GL::makeShader(GL_VERTEX_SHADER, vertFile);
  std::cout << "Creating fragment shader\n";
  GL::Shader fragShader = GL::makeShader(GL_FRAGMENT_SHADER, fragFile);
  
  program = GL::makeShaderProgram(vertShader, fragShader);
}

void RenderingSystem::quit() {
  indicies = nullptr;
  geometry = nullptr;
  vertArray = nullptr;
  texture = nullptr;
}

void RenderingSystem::onLevelLoad(Registry &registry) {
  const size_t numEntities = registry.view<ActiveSpriteRendering>().size();
  
  // @TODO store this in a static buffer and only generate it when the number of
  // indicies grows
  std::vector<ElemType> quadIndicies;
  for (size_t i = 0; i != numEntities; ++i) {
    quadIndicies.push_back(0);
    quadIndicies.push_back(1);
    quadIndicies.push_back(2);
    quadIndicies.push_back(2);
    quadIndicies.push_back(3);
    quadIndicies.push_back(0);
  }
  
  vertArray.bind();
  
  geometry = GL::makeArrayBuffer(numEntities * QUAD_ATTR_SIZE, GL_DYNAMIC_DRAW);
  indicies = GL::makeElementBuffer(quadIndicies.data(), numEntities * QUAD_ELEM_SIZE);
  
  posPointer(sizeof(PosType) + sizeof(TexCoordType), 0);
  enablePos();
  texCoordPointer(sizeof(PosType) + sizeof(TexCoordType), sizeof(PosType));
  enableTexCoord();
  
  GL::unbindVertexArray();
}
