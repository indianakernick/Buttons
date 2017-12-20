//
//  rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 19/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef rendering_system_hpp
#define rendering_system_hpp

#include <glm/mat3x3.hpp>
#include "entity registry.hpp"
#include <Unpacker/unpacker.hpp>
#include <Simpleton/OpenGL/buffer.hpp>
#include <Simpleton/OpenGL/texture.hpp>
#include <Simpleton/OpenGL/vertex array.hpp>
#include <Simpleton/OpenGL/shader program.hpp>

using PosType = glm::vec2;
using TexCoordType = glm::vec2;
using ElemType = unsigned short;

class RenderingSystem {
public:
  void init();
  void quit();
  
  const Unpack::Spritesheet &getSheet() const;
  void onLevelLoad(Registry &);
  void render(Registry &, const glm::mat3 &);

private:
  Unpack::Spritesheet sheet;
  GL::Texture2D texture;
  GL::ArrayBuffer arrayBuf;
  GL::ElementBuffer elemBuf;
  GL::VertexArray vertArray;
  GL::ShaderProgram program;
  size_t numQuads;
  GLint viewProjLoc;
  GLint texLoc;
  
  struct Vertex {
    PosType pos;
    TexCoordType texCoord;
  };
  
  std::vector<Vertex> verts;
  std::vector<ElemType> indicies;
  
  void fillIndicies(size_t);
  
  void activeSprites(Registry &);
};

#endif
