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
  constexpr GLint POS_ID = 0;
  constexpr GLint TEX_COORD_ID = 1;
  
  constexpr size_t QUAD_INDICIES = 6;
  constexpr size_t QUAD_VERTS = 4;
  constexpr size_t QUAD_ATTR_SIZE = (sizeof(PosType) + sizeof(TexCoordType)) * QUAD_VERTS;
  constexpr size_t QUAD_ELEM_SIZE = sizeof(ElemType) * QUAD_INDICIES;
  
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
  elemBuf = nullptr;
  arrayBuf = nullptr;
  vertArray = nullptr;
  texture = nullptr;
}

void RenderingSystem::onLevelLoad(Registry &registry) {
  const size_t numEntities = registry.view<ActiveSpriteRendering>().size();
  
  fillIndicies(numEntities);
  
  vertArray.bind();
  
  arrayBuf = GL::makeArrayBuffer(numEntities * QUAD_ATTR_SIZE, GL_DYNAMIC_DRAW);
  elemBuf = GL::makeElementBuffer(indicies.data(), numEntities * QUAD_ELEM_SIZE);
  
  posPointer(sizeof(PosType) + sizeof(TexCoordType), 0);
  enablePos();
  texCoordPointer(sizeof(PosType) + sizeof(TexCoordType), sizeof(PosType));
  enableTexCoord();
  
  GL::unbindVertexArray();
}

void RenderingSystem::fillIndicies(const size_t minSize) {
  if (indicies.size() * QUAD_INDICIES < minSize) {
    const size_t neededSize = minSize - indicies.size() / QUAD_INDICIES;
    for (size_t i = 0; i != neededSize; ++i) {
      indicies.push_back(0);
      indicies.push_back(1);
      indicies.push_back(2);
      indicies.push_back(2);
      indicies.push_back(3);
      indicies.push_back(0);
    }
  }
}
