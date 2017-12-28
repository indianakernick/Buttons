//
//  comp init.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef comp_init_hpp
#define comp_init_hpp

#include "json helper.hpp"
#include <Simpleton/ECS/registry.hpp>

class EntityIDmap;

template <typename Comp_>
class CompInit {
public:
  using Comp = Comp_;

  CompInit() = default;
  virtual ~CompInit() = default;
  
  void initialize(Comp &comp, const json &node, const EntityIDmap &idMap, const ECS::EntityID entity) {
    init(comp, node, idMap, entity);
  }

private:
  virtual void init(Comp &comp, const json &node, const EntityIDmap &idMap, ECS::EntityID) {
    init(comp, node, idMap);
  }
  virtual void init(Comp &comp, const json &node, const EntityIDmap &) {
    init(comp, node);
  }
  virtual void init(Comp &comp, const json &) {
    init(comp);
  }
  virtual void init(Comp &) {}
};

#endif
