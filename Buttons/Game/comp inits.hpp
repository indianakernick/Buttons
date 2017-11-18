//
//  comp inits.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef comp_inits_hpp
#define comp_inits_hpp

#include "comp init.hpp"
#include "component list.hpp"

class CompInits {
public:
  CompInits() = default;
  
  template <typename Comp>
  void init(Comp &comp, const YAML::Node &node, const EntityIDmap &idMap) {
    std::get<Utils::indexOf<CompList, Comp>>(inits).init(comp, node, idMap);
  }
  
private:
  #define COMP(NAME, ID_NAME) CompInit<NAME##Init, NAME>,
  #define LAST_COMP(NAME, ID_NAME) CompInit<NAME##Init, NAME>
  std::tuple<COMPS> inits;
  #undef LAST_COMP
  #undef COMP
};

#endif
