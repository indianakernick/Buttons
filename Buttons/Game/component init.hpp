//
//  component init.hpp
//  Buttons
//
//  Created by Indi Kernick on 9/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef component_init_hpp
#define component_init_hpp

#include "yaml helper.hpp"

template <typename Comp>
struct ComponentInit {
  static void init(Comp &comp, const YAML::Node &) {
    comp = {};
  }
};

template <typename Comp>
struct ComponentQuit {
  static void quit(Comp &) {}
};

#endif
