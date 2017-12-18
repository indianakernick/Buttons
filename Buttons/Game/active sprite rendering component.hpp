//
//  active sprite rendering component.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef active_sprite_rendering_component_hpp
#define active_sprite_rendering_component_hpp

#include <Unpacker/unpacker.hpp>

struct ActiveSpriteRendering {
  Unpack::SpriteID sprite;
  Unpack::SpriteID numFrames;
};

#endif
