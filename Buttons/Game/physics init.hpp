//
//  physics init.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef physics_init_hpp
#define physics_init_hpp

#include "physics component.hpp"
#include <Simpleton/ECS/registry.hpp>
#include <Simpleton/ECS/comp init.hpp>

class PhysicsBodyInit final : public ECS::CompInit<PhysicsBody> {
public:
  explicit PhysicsBodyInit(b2World *);
  
  void init(PhysicsBody &, const json &, const ECS::EntityIDmap &, ECS::EntityID) override;

private:
  b2World *world;
};

class PhysicsJointInit final : public ECS::CompInit<PhysicsJoint> {
public:
  PhysicsJointInit(b2World *, ECS::Registry *);
  
  void init(PhysicsJoint &, const json &, const ECS::EntityIDmap &, ECS::EntityID) override;

private:
  b2World *world;
  ECS::Registry *registry;
};

class PhysicsRayCastInit final : public ECS::CompInit<PhysicsRayCast> {
public:
  void init(PhysicsRayCast &, const json &) override;
};

#endif
