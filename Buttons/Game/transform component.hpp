//
//  transform component.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef transform_component_hpp
#define transform_component_hpp

#include <glm/vec2.hpp>

namespace YAML {
  class Node;
}
class EntityIDmap;

struct Transform {
  Transform(const YAML::Node &, const EntityIDmap &);

  glm::vec2 pos = {0.0f, 0.0f};
  glm::vec2 scale = {0.0f, 0.0f};
  float rotation = 0.0f;
};

#endif
