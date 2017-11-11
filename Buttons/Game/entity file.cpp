//
//  entity file.cpp
//  Buttons
//
//  Created by Indi Kernick on 10/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "entity file.hpp"

#include "yaml helper.hpp"
#include "component list.hpp"
#include "physics system.hpp"
#include <Simpleton/Platform/system info.hpp>

void loadComps(
  const EntityID id,
  const YAML::Node &comps,
  const EntityIDmap &idMap,
  Registry &registry,
  PhysicsSystem &physics
) {
  for (auto &pair : comps) {
    const std::string &compName = pair.first.Scalar();
    const YAML::Node &props = pair.second;
    Utils::getByName<CompList>(compName, [id, &idMap, &registry, &physics, props] (auto t) {
      using Comp = UTILS_TYPE(t);
      if constexpr (std::is_same_v<Comp, PhysicsBody>) {
        registry.accomodate<PhysicsBody>(id, props, idMap, *physics.getWorld());
      } else if constexpr (std::is_same_v<Comp, PhysicsJoint>) {
        registry.accomodate<PhysicsJoint>(id, props, idMap, *physics.getWorld());
      } else if constexpr (std::is_default_constructible_v<Comp>) {
        registry.accomodate<Comp>(id);
      } else {
        registry.accomodate<Comp>(id, props, idMap);
      }
    });
  }
}

void loadEntity(
  const EntityID id,
  const std::string &entityFileName,
  const YAML::Node &levelComps,
  const EntityIDmap &idMap,
  Registry &registry,
  PhysicsSystem &physics
) {
  const YAML::Node comps = YAML::LoadFile(Platform::getResDir() + entityFileName);
  checkType(comps, YAML::NodeType::Map);
  checkType(levelComps, YAML::NodeType::Map);
  loadComps(id, comps, idMap, registry, physics);
  loadComps(id, levelComps, idMap, registry, physics);
}
