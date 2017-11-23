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
  const auto iter = std::find(pairs.begin(), pairs.end(), sort(pair));
  if (iter != pairs.end()) {
    pairs.erase(iter);
  }
}

bool CollisionPairs::hasPair(const ObjectTypePair type) const {
  return find(type) != pairs.cend();
}

bool CollisionPairs::hasHalfPair(const ObjectTypeID type) const {
  return find(type) != pairs.cend();
}

bool CollisionPairs::hasAny() const {
  return !pairs.empty();
}

EntityPair CollisionPairs::getPair(const ObjectTypePair type) const {
  const auto iter = find(type);
  if (iter == pairs.cend()) {
    return NULL_ENTITY_PAIR;
  } else {
    return iter->entity;
  }
}

EntityID CollisionPairs::getHalfPair(const ObjectTypeID type) const {
  const auto iter = find(type);
  if (iter == pairs.cend()) {
    return NULL_ENTITY;
  } else {
    if (iter->type.first == type) {
      return iter->entity.first;
    } else {
      return iter->entity.second;
    }
  }
}

CollisionPairs::Pairs::iterator CollisionPairs::find(const ObjectTypePair type) {
  const auto pred = [type = sort(type)] (const CollisionPair pair) {
    return pair.type == type;
  };
  return std::find_if(pairs.begin(), pairs.end(), pred);
}

CollisionPairs::Pairs::const_iterator CollisionPairs::find(const ObjectTypePair type) const {
  const auto pred = [type = sort(type)] (const CollisionPair pair) {
    return pair.type == type;
  };
  return std::find_if(pairs.cbegin(), pairs.cend(), pred);
}

CollisionPairs::Pairs::const_iterator CollisionPairs::find(const ObjectTypeID type) const {
  const auto pred = [type] (const CollisionPair pair) {
    return pair.type.first == type || pair.type.second == type;
  };
  return std::find_if(pairs.cbegin(), pairs.cend(), pred);
}

ObjectTypePair CollisionPairs::sort(const ObjectTypePair pair) {
  if (pair.first < pair.second) {
    return pair;
  } else {
    return {pair.second, pair.first};
  }
}

CollisionPair CollisionPairs::sort(const CollisionPair pair) {
  if (pair.type.first < pair.type.second) {
    return pair;
  } else {
    return {
      {pair.type.second, pair.type.first},
      {pair.entity.second, pair.entity.first}
    };
  }
}
