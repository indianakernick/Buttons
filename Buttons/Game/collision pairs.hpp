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

class CollisionPairs {
public:
  CollisionPairs() = default;

  void addPair(CollisionPair);
  void remPair(CollisionPair);
  bool hasPair(CollisionPair) const;
  bool hasHalfPair(ObjectTypeID) const;
  bool hasAny() const;
  
  template <typename Type>
  bool hasPair(const ObjectTypeID typeID) const {
    return hasPair({getObjectTypeID<Type>(), typeID});
  }
  
  template <typename Type0, typename Type1>
  bool hasPair() const {
    return hasPair({getObjectTypeID<Type0>(), getObjectTypeID<Type1>()});
  }
  
  template <typename Type>
  bool hasHalfPair() const {
    return hasHalfPair(getObjectTypeID<Type>());
  }
  
private:
  std::vector<CollisionPair> pairs;
  
  static CollisionPair sort(CollisionPair);
};

#endif
