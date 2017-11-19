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

bool active(const State state) {
  return state == State::ACTIVE || state == State::ACTIVATING;
}

bool inactive(const State state) {
  return state == State::INACTIVE || state == State::DEACTIVATING;
}

void activate(State &state) {
  state = State::ACTIVATING;
}

void deactivate(State &state) {
  state = State::DEACTIVATING;
}
