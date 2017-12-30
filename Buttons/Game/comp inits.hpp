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
#include "component list.hpp"
#include <Simpleton/Utils/tuple.hpp>
#include <Simpleton/ECS/comp init.hpp>

class CompInits {
public:
  CompInits() = default;
  
  ///Initializes the given component
  template <typename Comp>
  void init(
    Comp &comp,
    const json &node,
    const ECS::EntityIDmap &idMap,
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
  template <typename Comp>
  struct InitPointer {
    using type = std::unique_ptr<ECS::CompInit<Comp>>;
  };
  Utils::ListToTuple<Utils::TransformList<CompList, InitPointer>> inits;
  
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
