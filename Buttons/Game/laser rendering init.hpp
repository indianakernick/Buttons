//
//  laser rendering init.hpp
//  Buttons
//
//  Created by Indi Kernick on 22/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef laser_rendering_init_hpp
#define laser_rendering_init_hpp

#include <Simpleton/ECS/comp init.hpp>
#include "laser rendering component.hpp"

class LaserRenderingInit final : public ECS::CompInit<LaserRendering> {
public:
  void init(LaserRendering &, const json &) override;
};

#endif
