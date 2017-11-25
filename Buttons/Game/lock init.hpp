//
//  lock init.hpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef lock_init_hpp
#define lock_init_hpp

#include "comp init.hpp"
#include "lock component.hpp"

class LockInit final : public CompInit<Lock> {
public:
  void init(Lock &, const YAML::Node &);
};

#endif
