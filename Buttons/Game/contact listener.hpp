//
//  contact listener.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef contact_listener_hpp
#define contact_listener_hpp

#include <functional>
#include "object types.hpp"
#include "entity constants.hpp"
#include "../Libraries/Box2D/Dynamics/b2WorldCallbacks.h"

class ContactListener final : public b2ContactListener {
public:
  using Listener = std::function<void (EntityID, EntityID, CollisionPair)>;

  ContactListener() = default;
  
  void BeginContact(b2Contact *) override;
  void EndContact(b2Contact *) override;
  
  void setBeginListener(const Listener &);
  void setEndListener(const Listener &);
  
private:
  Listener beginListener;
  Listener endListener;
};

#endif
