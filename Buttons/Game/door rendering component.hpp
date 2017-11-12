//
//  door rendering component.hpp
//  Buttons
//
//  Created by Indi Kernick on 12/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef door_rendering_component_hpp
#define door_rendering_component_hpp

#include <Simpleton/Math/dir.hpp>

namespace YAML {
  class Node;
}
class EntityIDmap;

struct DoorRendering {
  DoorRendering(const YAML::Node &, const EntityIDmap &);
  
  Math::Dir closeDir;
};

#endif
