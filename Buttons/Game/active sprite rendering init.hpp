//
//  active sprite rendering init.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef active_sprite_rendering_init_hpp
#define active_sprite_rendering_init_hpp

#include "comp init.hpp"
#include "active sprite rendering component.hpp"

namespace Unpack {
  class Spritesheet;
}

class ActiveSpriteRenderingInit final : public CompInit<ActiveSpriteRendering> {
public:
  explicit ActiveSpriteRenderingInit(const Unpack::Spritesheet &);

  void init(ActiveSpriteRendering &, const json &);

private:
  const Unpack::Spritesheet &sheet;
};

#endif
