//
//  animation init.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef animation_init_hpp
#define animation_init_hpp

#include "animation component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class AnimationInit final : public ECS::CompInit<Animation> {
public:
  void init(Animation &, const json &) override;
};

#endif
