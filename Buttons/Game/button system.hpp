//
//  button system.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef button_system_hpp
#define button_system_hpp

#include <Simpleton/ECS/registry.hpp>

///Activates an entity when a button base is colliding with a button top. (Button base)
void buttonSystem(ECS::Registry &);

#endif
