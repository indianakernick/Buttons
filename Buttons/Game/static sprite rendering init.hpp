//
//  static sprite rendering init.hpp
//  Buttons
//
//  Created by Indi Kernick on 21/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef static_sprite_rendering_init_hpp
#define static_sprite_rendering_init_hpp

#include "comp init.hpp"
#include "static sprite rendering component.hpp"

class StaticSpriteRenderingInit final : public CompInit<StaticSpriteRendering> {
public:
  explicit StaticSpriteRenderingInit(const Unpack::Spritesheet &);
  
  void init(StaticSpriteRendering &, const json &) override;
  
private:
  const Unpack::Spritesheet &sheet;
};

#endif
