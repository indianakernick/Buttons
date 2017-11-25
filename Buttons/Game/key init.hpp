//
//  key init.hpp
//  Buttons
//
//  Created by Indi Kernick on 25/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef key_init_hpp
#define key_init_hpp

#include "comp init.hpp"
#include "key component.hpp"

class KeyInit final : public CompInit<Key> {
public:
  void init(Key &, const YAML::Node &);
};

#endif
