//
//  rendering system.hpp
//  Buttons
//
//  Created by Indi Kernick on 19/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef rendering_system_hpp
#define rendering_system_hpp

#include <Unpacker/unpacker.hpp>
#include <Simpleton/OpenGL/texture.hpp>

class RenderingSystem {
public:
  void init();
  void quit();

private:
  Unpack::Spritesheet sheet;
  GL::Texture texture;
};

#endif
