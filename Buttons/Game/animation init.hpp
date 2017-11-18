//
//  animation init.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef animation_init_hpp
#define animation_init_hpp

#include "comp init.hpp"
#include "animation component.hpp"

class AnimationInit final : public CompInit<Animation> {
public:
  void init(Animation &, const YAML::Node &) override;
};

#endif
