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
#include "entity constants.hpp"

using ObjectTypePair = std::pair<ObjectTypeID, ObjectTypeID>;
using EntityPair = std::pair<EntityID, EntityID>;

struct CollisionPair {
  ObjectTypePair type;
  EntityPair entity;
};

inline bool operator==(const CollisionPair left, const CollisionPair right) {
  return left.type == right.type && left.entity == right.entity;
}

constexpr EntityPair NULL_ENTITY_PAIR = {NULL_ENTITY, NULL_ENTITY};

class CollisionPairs {
public:
  CollisionPairs() = default;

  void addPair(CollisionPair);
  void remPair(CollisionPair);
  
  bool hasPair(ObjectTypePair) const;
  bool hasHalfPair(ObjectTypeID) const;
  bool hasAny() const;
  
  EntityPair getPair(ObjectTypePair) const;
  EntityID getHalfPair(ObjectTypeID) const;
  
  template <typename Type0, typename Type1>
  bool hasPair() const {
    return hasPair({getObjectTypeID<Type0>(), getObjectTypeID<Type1>()});
  }
  
  template <typename Type>
  bool hasHalfPair() const {
    return hasHalfPair(getObjectTypeID<Type>());
  }
  
  template <typename Type0, typename Type1>
  EntityPair getPair() const {
    return getPair({getObjectTypeID<Type0>(), getObjectTypeID<Type1>()});
  }
  
  template <typename Type>
  EntityID getHalfPair() const {
    return getHalfPair(getObjectTypeID<Type>());
  }
  
private:
  using Pairs = std::vector<CollisionPair>;
  Pairs pairs;
  
  Pairs::iterator find(ObjectTypePair);
  Pairs::const_iterator find(ObjectTypePair) const;
  Pairs::const_iterator find(ObjectTypeID) const;
  
  static ObjectTypePair sort(ObjectTypePair);
  static CollisionPair sort(CollisionPair);
};

#endif
