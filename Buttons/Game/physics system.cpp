//
//  physics system.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "physics system.hpp"

#include <algorithm>
#include "physics component.hpp"
#include "physics constants.hpp"
#include <Simpleton/Utils/member function.hpp>

void PhysicsSystem::init(Registry &newRegistry) {
  world.emplace(GRAVITY);
  
  contactListener.emplace();
  world->SetContactListener(&(*contactListener));
  contactListener->setBeginListener(Utils::memFun(this, &PhysicsSystem::beginContact));
  contactListener->setEndListener(Utils::memFun(this, &PhysicsSystem::endContact));
  
  debugDraw.emplace();
  world->SetDebugDraw(&(*debugDraw));
  
  registry = &newRegistry;
}

void PhysicsSystem::quit() {
  registry = nullptr;
  
  world->SetDebugDraw(nullptr);
  debugDraw = std::experimental::nullopt;
  
  contactListener->setEndListener(nullptr);
  contactListener->setBeginListener(nullptr);
  world->SetContactListener(nullptr);
  contactListener = std::experimental::nullopt;
  
  world = std::experimental::nullopt;
}

b2World *PhysicsSystem::getWorld() {
  return &(*world);
}

namespace {
  class FindClosest final : public b2RayCastCallback {
  public:
    float32 ReportFixture(
      b2Fixture *const fixture,
      const b2Vec2 &,
      const b2Vec2 &,
      const float32 fraction
    ) override {
      if (fixture->IsSensor()) {
        return -1.0f;
      } else {
        return closest = fraction;
      }
    }
    
    float32 getClosest() const {
      return closest;
    }
    
  private:
    float32 closest = 1.0f;
  };
}

void PhysicsSystem::update(const float delta) {
  world->Step(delta, VELOCITY_ITER, POSITION_ITER);
  auto view = registry->view<PhysicsRayCast>();
  for (const EntityID entity : view) {
    PhysicsRayCast &comp = view.get(entity);
    FindClosest callback;
    world->RayCast(&callback, comp.start, comp.end);
    comp.closestFraction = callback.getClosest();
  }
}

void PhysicsSystem::render() {
  world->DrawDebugData();
}

void PhysicsSystem::beginContact(const CollisionPair pair) {
  if (registry->has<Collision>(pair.entity.first)) {
    registry->get<Collision>(pair.entity.first).collisionPairs.addPair(pair);
  }
  if (registry->has<Collision>(pair.entity.second)) {
    registry->get<Collision>(pair.entity.second).collisionPairs.addPair(pair);
  }
}

void PhysicsSystem::endContact(const CollisionPair pair) {
  if (registry->has<Collision>(pair.entity.first)) {
    registry->get<Collision>(pair.entity.first).collisionPairs.remPair(pair);
  }
  if (registry->has<Collision>(pair.entity.second)) {
    registry->get<Collision>(pair.entity.second).collisionPairs.remPair(pair);
  }
}
