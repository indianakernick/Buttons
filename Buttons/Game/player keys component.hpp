//
//  player keys component.hpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef player_keys_component_hpp
#define player_keys_component_hpp

#include <bitset>

constexpr size_t MAX_KEYS = 64;

struct PlayerKeys {
  std::bitset<MAX_KEYS> keys;
};

#endif
