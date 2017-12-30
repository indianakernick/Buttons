//
//  anim sprite rendering init.hpp
//  Buttons
//
//  Created by Indi Kernick on 21/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef anim_sprite_rendering_init_hpp
#define anim_sprite_rendering_init_hpp

#include <Simpleton/ECS/comp init.hpp>
#include "anim sprite rendering component.hpp"

class AnimSpriteRenderingInit final : public ECS::CompInit<AnimSpriteRendering> {
public:
  explicit AnimSpriteRenderingInit(const Unpack::Spritesheet &);
  
  void init(AnimSpriteRendering &, const json &) override;

private:
  const Unpack::Spritesheet &sheet;
};

#endif
