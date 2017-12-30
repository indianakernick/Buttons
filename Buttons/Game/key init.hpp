//
//  key init.hpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef key_init_hpp
#define key_init_hpp

#include "key component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class KeyInit final : public ECS::CompInit<Key> {
public:
  void init(Key &, const json &);
};

#endif
