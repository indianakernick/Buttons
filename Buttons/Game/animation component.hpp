//
//  animation component.hpp
//  Buttons
//
//  Created by Indi Kernick on 12/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef animation_component_hpp
#define animation_component_hpp

struct Animation {
  float progress = 0.0f;
  float speed = 1.0f;
  
  enum class EdgeMode {
    REPEAT,
    CHANGE_DIR
  };
  
  EdgeMode edgeMode = EdgeMode::REPEAT;
};

#endif
