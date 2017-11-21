//
//  text init.hpp
//  Buttons
//
//  Created by Indi Kernick on 21/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef text_init_hpp
#define text_init_hpp

#include "comp init.hpp"
#include "text component.hpp"

class TextInit final : public CompInit<Text> {
public:
  void init(Text &, const YAML::Node &) override;
};

#endif
