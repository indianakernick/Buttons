//
//  transform init.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef transform_init_hpp
#define transform_init_hpp

#include "comp init.hpp"
#include "transform component.hpp"

class TransformInit final : public CompInit<Transform> {
public:
  void init(Transform &, const json &) override;
};

#endif
