//
//  physics component.cpp
//  Buttons
//
//  Created by Indi Kernick on 9/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "physics component.hpp"

#include "physics file.hpp"
#include "component init.hpp"
#include "../Libraries/Box2D/Dynamics/b2World.h"

template <>
struct ComponentInit<PhysicsBody> {
  static void init(PhysicsBody &comp, const YAML::Node &node, b2World &world) {
    comp.body = loadBody(getChild(node, "body").Scalar(), world, node.as<Transform>());
  }
};

template <>
struct ComponentQuit<PhysicsBody> {
  static void quit(PhysicsBody &comp, b2World &world) {
    if (b2Body *const body = comp.body) {
      world.DestroyBody(body);
    }
  }
};

template <>
struct ComponentInit<PhysicsJoint> {
  static void init(PhysicsJoint &comp, const YAML::Node &node, b2World &world) {
    
  }
};
