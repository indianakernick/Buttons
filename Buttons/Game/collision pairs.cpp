//
//  collision pairs.cpp
//  Buttons
//
//  Created by Indi Kernick on 8/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "collision pairs.hpp"

void CollisionPairs::addPair(const CollisionPair pair) {
  pairs.push_back(sort(pair));
}

void CollisionPairs::remPair(const CollisionPair pair) {
  if (pairs.size() != 0) {
    //erasing at the end is faster than erasing at the beginning
    const auto iter = std::find(pairs.crbegin(), pairs.crend(), sort(pair));
    if (iter != pairs.crend()) {
      pairs.erase(iter.base() - 1);
    }
  }
}

bool CollisionPairs::hasPair(const CollisionPair pair) const {
  return std::find(pairs.cbegin(), pairs.cend(), sort(pair)) != pairs.cend();
}

bool CollisionPairs::hasHalfPair(const ObjectTypeID typeID) const {
  return std::any_of(pairs.cbegin(), pairs.cend(), [typeID] (const auto pair) {
    return pair.first == typeID || pair.second == typeID;
  });
}

bool CollisionPairs::hasAny() const {
  return !pairs.empty();
}

CollisionPair CollisionPairs::sort(const CollisionPair pair) {
  if (pair.first < pair.second) {
    return pair;
  } else {
    return {pair.second, pair.first};
  }
}
