//
//  activation component.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef activation_component_hpp
#define activation_component_hpp

namespace YAML {
  class Node;
}
class EntityIDmap;

struct Activation {
  Activation(const YAML::Node &, const EntityIDmap &);

  // 0.0f is inactive
  // 1.0f is active
  float activity = 0.0f;
  // How quickly the activity changes
  // 0.0f means instantly
  float speed = 0.0f;
  
  enum class State {
    ACTIVATING,
    DEACTIVATING,
    ACTIVE,
    INACTIVE
  };
  
  State state = State::INACTIVE;
};

#endif
