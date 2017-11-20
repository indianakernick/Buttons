//
//  activation component.cpp
//  Buttons
//
//  Created by Indi Kernick on 9/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "activation component.hpp"

namespace {
  using State = Activation::State;
}

bool isActive(const State state) {
  return state == State::ACTIVE || state == State::ACTIVATING;
}

bool isInactive(const State state) {
  return state == State::INACTIVE || state == State::DEACTIVATING;
}

void activate(State &state) {
  if (state != State::ACTIVE) {
    state = State::ACTIVATING;
  }
}

void deactivate(State &state) {
  if (state != State::INACTIVE) {
    state = State::DEACTIVATING;
  }
}
