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
  const auto iter = std::find(pairs.cbegin(), pairs.cend(), sort(pair));
  if (iter != pairs.cend()) {
    pairs.erase(iter);
  }
}

bool CollisionPairs::hasPair(const ObjectTypePair type) const {
  return find(type) != pairs.cend();
}

bool CollisionPairs::hasHalfPair(const B2::ObjectTypeID type) const {
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

ECS::EntityID CollisionPairs::getHalfPair(const B2::ObjectTypeID type) const {
  const auto iter = find(type);
  if (iter == pairs.cend()) {
    return ECS::NULL_ENTITY;
  } else {
    if (iter->type.first == type) {
      return iter->entity.first;
    } else {
      return iter->entity.second;
    }
  }
}

auto CollisionPairs::searchPred(const ObjectTypePair type) {
  return [type = sort(type)] (const CollisionPair pair) {
    return pair.type == type;
  };
}

auto CollisionPairs::searchPred(const B2::ObjectTypeID type) {
  return [type] (const CollisionPair pair) {
    return pair.type.first == type || pair.type.second == type;
  };
}

CollisionPairs::Iter CollisionPairs::find(const ObjectTypePair type) const {
  return std::find_if(pairs.cbegin(), pairs.cend(), searchPred(type));
}

CollisionPairs::Iter CollisionPairs::find(const B2::ObjectTypeID type) const {
  return std::find_if(pairs.cbegin(), pairs.cend(), searchPred(type));
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
