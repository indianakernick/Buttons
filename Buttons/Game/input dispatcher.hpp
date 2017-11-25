//
//  input dispatcher.hpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef input_dispatcher_hpp
#define input_dispatcher_hpp

#include <Simpleton/Utils/dispatcher.hpp>

extern "C" union SDL_Event;

using InputDispatcher = Utils::Handlable<uint32_t, const SDL_Event &>;

#endif
