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
#include <experimental/optional>

class CompInits {
public:
  CompInits() = default;
  
  ///Initializes the given component
  template <typename Comp>
  void init(
    Comp &comp,
    const YAML::Node &node,
    const EntityIDmap &idMap,
    const EntityID entity
  ) {
    getInit<Comp>().value().init(comp, node, idMap, entity);
  }
  
  ///Constructs the initializer for the given component
  template <typename Comp, typename ...Args>
  void construct(Args &&... args) {
    getInit<Comp>().emplace(std::forward<Args>(args)...);
  }
  
  ///Default constructs all initializers that haven't been constructed
  void defaultConstructAll() {
    Utils::forEach(init, [] (auto &init) {
      if (!init) {
        init.emplace();
      }
    });
  }
  
private:
  #define COMP(NAME, ID_NAME) std::experimental::optional<NAME##Init>,
  #define LAST_COMP(NAME, ID_NAME) std::experimental::optional<NAME##Init>
  std::tuple<COMPS> inits;
  #undef LAST_COMP
  #undef COMP
  
  template <typename Comp>
  auto getInit() {
    return std::get<Utils::indexOf<CompList, Comp>>(inits);
  }
};

#endif
