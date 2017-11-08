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
  void addPair(CollisionPair);
  void remPair(CollisionPair);
  bool hasPair(CollisionPair) const;
  
  template <typename Type>
  bool hasPair(const ObjectTypeID typeID) const {
    return hasPair({getObjectTypeID<Type>(), typeID});
  }
  
  template <typename Type0, typename Type1>
  bool hasPair() const {
    return hasPair({getObjectTypeID<Type0>(), getObjectTypeID<Type1>()});
  }
  
private:
  std::vector<CollisionPair> pairs;
  
  static CollisionPair sort(CollisionPair);
};

#endif
