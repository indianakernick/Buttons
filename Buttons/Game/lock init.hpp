//
//  lock init.hpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef lock_init_hpp
#define lock_init_hpp

#include "lock component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class LockInit final : public ECS::CompInit<Lock> {
public:
  void init(Lock &, const json &);
};

#endif
