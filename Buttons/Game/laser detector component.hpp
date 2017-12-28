//
//  laser detector component.hpp
//  Buttons
//
//  Created by Indi Kernick on 19/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef laser_detector_component_hpp
#define laser_detector_component_hpp

#include <Simpleton/ECS/registry.hpp>

struct LaserDetector {
  ECS::EntityID emitter;
};

#endif
