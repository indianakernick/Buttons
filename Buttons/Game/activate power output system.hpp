//
//  activate power output system.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef activate_power_output_system_hpp
#define activate_power_output_system_hpp

#include "entity constants.hpp"
#include <entt/entity/registry.hpp>

///Outputs power when the entity is active. (Button, Switch, Laser Sensor)
void activatePowerOutputSystem(entt::Registry<EntityID> &);

#endif
