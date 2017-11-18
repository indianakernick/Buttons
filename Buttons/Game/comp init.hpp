//
//  comp init.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef comp_init_hpp
#define comp_init_hpp

#include "entity constants.hpp"

namespace YAML {
  class Node;
}
class EntityIDmap;

template <typename Comp_>
class CompInit {
public:
  using Comp = Comp_;

  CompInit() = default;
  virtual ~CompInit() = default;
  
  void initialize(Comp &comp, const YAML::Node &node, const EntityIDmap &idMap, const EntityID entity) {
    init(comp, node, idMap, entity);
  }

private:
  virtual void init(Comp &comp, const YAML::Node &node, const EntityIDmap &idMap, EntityID) {
    init(comp, node, idMap);
  }
  virtual void init(Comp &comp, const YAML::Node &node, const EntityIDmap &) {
    init(comp, node);
  }
  virtual void init(Comp &comp, const YAML::Node &) {
    init(comp);
  }
  virtual void init(Comp &) {}
};

#endif
