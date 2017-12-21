//
//  anim sprite rendering component.hpp
//  Buttons
//
//  Created by Indi Kernick on 21/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef anim_sprite_rendering_component_hpp
#define anim_sprite_rendering_component_hpp

#include <Unpacker/unpacker.hpp>

struct AnimSpriteRendering {
  Unpack::SpriteID sprite;
  Unpack::SpriteID frames;
};

#endif
