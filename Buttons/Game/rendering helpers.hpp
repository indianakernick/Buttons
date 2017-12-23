//
//  rendering helpers.hpp
//  Buttons
//
//  Created by Indi Kernick on 22/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef rendering_helpers_hpp
#define rendering_helpers_hpp

#include <array>
#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/mat3x3.hpp>
#include <Unpacker/unpacker.hpp>

using PosType = glm::vec3;
using TexCoordType = glm::vec2;
using ElemType = unsigned short;

struct Vertex {
  PosType pos;
  TexCoordType texCoord;
};
using Quad = std::array<Vertex, 4>;

using Quads = std::vector<Quad>;
using QuadIter = typename Quads::iterator;
using Elems = std::vector<ElemType>;

struct TexCoords {
  glm::vec2 bottomLeft;
  glm::vec2 topRight;
};

using Unpack::Spritesheet;
using Unpack::SpriteID;

const glm::vec2 CORNER[4] = {
  {0.0f, 0.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 1.0f}
};

TexCoords lookupTexCoords(const Spritesheet &, SpriteID);
glm::vec3 mulPos(const glm::mat3 &, glm::vec2, float);
SpriteID getAnimFrame(float, SpriteID, SpriteID);
void setTexCoords(Quad &, TexCoords);

#endif
