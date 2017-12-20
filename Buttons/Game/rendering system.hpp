//
//  rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 19/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef rendering_system_hpp
#define rendering_system_hpp

#include "entity registry.hpp"
#include <Unpacker/unpacker.hpp>
#include <Simpleton/OpenGL/buffer.hpp>
#include <Simpleton/OpenGL/texture.hpp>
#include <Simpleton/OpenGL/vertex array.hpp>
#include <Simpleton/OpenGL/shader program.hpp>

class RenderingSystem {
public:
  void init();
  void quit();
  
  void onLevelLoad(Registry &);

private:
  Unpack::Spritesheet sheet;
  GL::Texture2D texture;
  GL::ArrayBuffer geometry;
  GL::ElementBuffer indicies;
  GL::VertexArray vertArray;
  GL::ShaderProgram program;
};

#endif
