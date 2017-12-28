//
//  collision pairs.hpp
//  Buttons
//
//  Created by Indi Kernick on 8/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef collision_pairs_hpp
#define collision_pairs_hpp

#include <vector>
#include <utility>
#include "object types.hpp"
#include <Simpleton/ECS/registry.hpp>

using ObjectTypePair = std::pair<B2::ObjectTypeID, B2::ObjectTypeID>;
using EntityPair = std::pair<ECS::EntityID, ECS::EntityID>;

struct CollisionPair {
  ObjectTypePair type;
  EntityPair entity;
};

inline bool operator==(const CollisionPair left, const CollisionPair right) {
  return left.type == right.type && left.entity == right.entity;
}

constexpr EntityPair NULL_ENTITY_PAIR = {ECS::NULL_ENTITY, ECS::NULL_ENTITY};

class CollisionPairs {
public:
  CollisionPairs() = default;

  void addPair(CollisionPair);
  void remPair(CollisionPair);
  
  bool hasPair(ObjectTypePair) const;
  bool hasHalfPair(B2::ObjectTypeID) const;
  bool hasAny() const;
  
  EntityPair getPair(ObjectTypePair) const;
  ECS::EntityID getHalfPair(B2::ObjectTypeID) const;
  
  template <typename Type0, typename Type1>
  bool hasPair() const {
    return hasPair({B2::getObjectTypeID<Type0>(), B2::getObjectTypeID<Type1>()});
  }
  
  template <typename Type>
  bool hasHalfPair() const {
    return hasHalfPair(B2::getObjectTypeID<Type>());
  }
  
  template <typename Type0, typename Type1>
  EntityPair getPair() const {
    return getPair({B2::getObjectTypeID<Type0>(), B2::getObjectTypeID<Type1>()});
  }
  
  template <typename Type>
  ECS::EntityID getHalfPair() const {
    return getHalfPair(B2::getObjectTypeID<Type>());
  }
  
private:
  using Pairs = std::vector<CollisionPair>;
  using Iter = Pairs::const_iterator;
  Pairs pairs;
  
  static auto searchPred(ObjectTypePair);
  static auto searchPred(B2::ObjectTypeID);
  
  Iter find(ObjectTypePair) const;
  Iter find(B2::ObjectTypeID) const;
  
  static ObjectTypePair sort(ObjectTypePair);
  static CollisionPair sort(CollisionPair);
};

#endif
