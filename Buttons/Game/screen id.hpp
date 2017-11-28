//
//  screen id.hpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef screen_id_hpp
#define screen_id_hpp

#include <Simpleton/ID/type.hpp>

using ScreenID = size_t;

class Screen;

template <typename ScreenClass>
inline ScreenID getScreenID() {
  return ID::TypeCounter<ScreenID, ScreenClass, Screen>::get();
}

#endif
