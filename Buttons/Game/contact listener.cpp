//
//  contact listener.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "contact listener.hpp"

#include <utility>
#include "physics body entity id.hpp"
#include "../Libraries/Box2D/Dynamics/Contacts/b2Contact.h"

namespace {
  std::pair<EntityID, EntityID> getEntityPair(b2Contact *const contact) {
    return {
      getEntity(contact->GetFixtureA()->GetBody()->GetUserData()),
      getEntity(contact->GetFixtureB()->GetBody()->GetUserData())
    };
  }
  
  CollisionPair getCollisionPair(b2Contact *const contact) {
    return {
      getObjectTypeID(contact->GetFixtureA()->GetUserData()),
      getObjectTypeID(contact->GetFixtureB()->GetUserData())
    };
  }
}

void ContactListener::BeginContact(b2Contact *const contact) {
  if (beginListener) {
    const auto [entityA, entityB] = getEntityPair(contact);
    beginListener(entityA, entityB, getCollisionPair(contact));
  }
}

void ContactListener::EndContact(b2Contact *const contact) {
  if (endListener) {
    const auto [entityA, entityB] = getEntityPair(contact);
    endListener(entityA, entityB, getCollisionPair(contact));
  }
}

void ContactListener::setBeginListener(const Listener &newListener) {
  beginListener = newListener;
}

void ContactListener::setEndListener(const Listener &newListener) {
  endListener = newListener;
}
