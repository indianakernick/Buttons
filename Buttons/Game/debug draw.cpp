//
//  debug draw.cpp
//  Catastrophe
//
//  Created by Indi Kernick on 30/7/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "debug draw.hpp"

#include "physics constants.hpp"

DebugDraw::DebugDraw()
  : b2Draw() {
  m_drawFlags =
    (ENABLE_SHAPE_RENDER ? e_shapeBit : 0) |
    (ENABLE_JOINT_RENDER ? e_jointBit : 0) |
    (ENABLE_AABB_RENDER ? e_aabbBit : 0) |
    (ENABLE_PAIR_RENDER ? e_pairBit : 0) |
    (ENABLE_CENTER_OF_MASS_RENDER ? e_centerOfMassBit : 0)
  ;
}

void DebugDraw::DrawPolygon(const b2Vec2 *, const int32, const b2Color &) {
  
}

void DebugDraw::DrawSolidPolygon(const b2Vec2 *, const int32, const b2Color &) {
  
}

void DebugDraw::DrawCircle(const b2Vec2 &, const float32, const b2Color &) {
  
}

void DebugDraw::DrawSolidCircle(const b2Vec2 &, const float32, const b2Vec2 &, const b2Color &) {
  
}

void DebugDraw::DrawSegment(const b2Vec2 &, const b2Vec2 &, const b2Color &) {
  
}

void DebugDraw::DrawTransform(const b2Transform &) {
  
}

void DebugDraw::DrawPoint(const b2Vec2 &, const float32, const b2Color &) {
  
}
