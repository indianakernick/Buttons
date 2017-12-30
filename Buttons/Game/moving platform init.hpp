//
//  moving platform init.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef moving_platform_init_hpp
#define moving_platform_init_hpp

#include <Simpleton/ECS/comp init.hpp>
#include "moving platform component.hpp"

class MovingPlatformInit final : public ECS::CompInit<MovingPlatform> {
public:
  void init(MovingPlatform &, const json &) override;
};

#endif
