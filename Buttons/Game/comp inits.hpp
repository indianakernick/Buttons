//
//  comp inits.hpp
//  Buttons
//
//  Created by Indi Kernick on 18/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef comp_inits_hpp
#define comp_inits_hpp

#include <memory>
#include "comp init.hpp"
#include "component list.hpp"
#include <Simpleton/Utils/tuple.hpp>

class CompInits {
public:
  CompInits() = default;
  
  ///Initializes the given component
  template <typename Comp>
  void init(
    Comp &comp,
    const json &node,
    const EntityIDmap &idMap,
    const ECS::EntityID entity
  ) const {
    assert(getInit<Comp>());
    getInit<Comp>()->initialize(comp, node, idMap, entity);
  }
  
  ///Constructs the initializer for the given component
  template <typename CompInit, typename ...Args>
  void construct(Args &&... args) {
    using Comp = typename CompInit::Comp;
    getInit<Comp>() = std::make_unique<CompInit>(std::forward<Args>(args)...);
  }
  
  ///Creates default initializers for components that don't have initializers
  void setDefaults() {
    Utils::forEach(inits, [] (auto &init) {
      if (!init) {
        using UniquePtr = std::remove_reference_t<decltype(init)>;
        init = std::make_unique<typename UniquePtr::element_type>();
      }
    });
  }
  
  ///Destroys all component initializers
  void destroyAll() {
    Utils::forEach(inits, [] (auto &init) {
      init.reset();
    });
  }
  
private:
  #define COMP(NAME, ID_NAME) std::unique_ptr<CompInit<NAME>>,
  #define LAST_COMP(NAME, ID_NAME) std::unique_ptr<CompInit<NAME>>
  std::tuple<COMPS> inits;
  #undef LAST_COMP
  #undef COMP
  
  template <typename Comp>
  auto &getInit() {
    return std::get<Utils::indexOf<CompList, Comp>>(inits);
  }
  
  template <typename Comp>
  auto &getInit() const {
    return std::get<Utils::indexOf<CompList, Comp>>(inits);
  }
};

#endif
