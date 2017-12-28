//
//  contact listener.cpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "contact listener.hpp"

#include <utility>
#include <Simpleton/Box2D/entity id.hpp>
#include <Box2D/Dynamics/Contacts/b2Contact.h>

namespace {
  ObjectTypePair getTypePair(b2Contact *const contact) {
    return {
      getObjectTypeID(contact->GetFixtureA()->GetUserData()),
      getObjectTypeID(contact->GetFixtureB()->GetUserData())
    };
  }
  
  EntityPair getEntityPair(b2Contact *const contact) {
    return {
      B2::getEntity(contact->GetFixtureA()->GetBody()->GetUserData()),
      B2::getEntity(contact->GetFixtureB()->GetBody()->GetUserData())
    };
  }
  
  CollisionPair getCollisionPair(b2Contact *const contact) {
    return {getTypePair(contact), getEntityPair(contact)};
  }
}

void ContactListener::BeginContact(b2Contact *const contact) {
  if (beginListener) {
    beginListener(getCollisionPair(contact));
  }
}

void ContactListener::EndContact(b2Contact *const contact) {
  if (endListener) {
    endListener(getCollisionPair(contact));
  }
}

void ContactListener::setBeginListener(const Listener &newListener) {
  beginListener = newListener;
}

void ContactListener::setEndListener(const Listener &newListener) {
  endListener = newListener;
}
