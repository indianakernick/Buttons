//
//  rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 19/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef rendering_system_hpp
#define rendering_system_hpp

#include "rendering helpers.hpp"
#include <Simpleton/ECS/registry.hpp>
#include <Simpleton/OpenGL/buffer.hpp>
#include <Simpleton/OpenGL/texture.hpp>
#include <Simpleton/OpenGL/vertex array.hpp>
#include <Simpleton/OpenGL/shader program.hpp>

class RenderingSystem {
public:
  void init();
  void quit();
  
  const Unpack::Spritesheet &getSheet() const;
  void onLevelLoad(ECS::Registry &);
  void render(ECS::Registry &, const glm::mat3 &);

private:
  Spritesheet sheet;
  GL::Texture2D texture;
  GL::ArrayBuffer arrayBuf;
  GL::ElementBuffer elemBuf;
  GL::VertexArray vertArray;
  GL::ShaderProgram program;
  size_t numQuads;
  GLint viewProjLoc;
  GLint texLoc;
  
  Quads quads;
  Elems indicies;
  
  void fillIndicies(size_t);
  void fillVBOs();
};

#endif
