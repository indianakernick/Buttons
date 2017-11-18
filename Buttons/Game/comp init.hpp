//
//  comp init.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef comp_init_hpp
#define comp_init_hpp

#include <type_traits>

namespace YAML {
  class Node;
}
class EntityIDmap;

template <typename Init, typename Comp>
class CompInit {
  template <typename>
  static std::true_type check(void (Init::*init)(Comp &, const YAML::Node &, const EntityIDmap &));
  template <typename>
  static std::false_type check(...);
  
  static constexpr bool HAS_INIT = std::is_same_v<decltype(check(nullptr)), std::true_type>;
  
public:
  ~CompInit() {
    static_assert(std::is_base_of_v<CompInit, Init>);
  }
  
  void init(Comp &comp, const YAML::Node &node, const EntityIDmap &idMap) {
    if constexpr (HAS_INIT) {
      Init::init(comp, node, idMap);
    }
  }
};

template <typename Comp>
class CompInit<void, Comp> {
public:
  void init(Comp &, const YAML::Node &, const EntityIDmap &) {}
};

#endif
