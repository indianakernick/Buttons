//
//  moving platform component.hpp
//  Buttons
//
//  Created by Indi Kernick on 16/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef moving_platform_component_hpp
#define moving_platform_component_hpp

#include <Box2D/Common/b2Math.h>

struct MovingPlatform {
  static constexpr float PISTON = std::numeric_limits<float>::max();

  b2Vec2 start;
  b2Vec2 end;
  float waitingTime = 1.0f;
  float moveSpeed = 1.0f;
  float timeTillFinishWait = 0.0f;
  enum class State {
    AT_START,
    TO_END,
    WAIT_AT_END,
    TO_START,
    WAIT_AT_START
  } state = State::AT_START;
};

#endif
