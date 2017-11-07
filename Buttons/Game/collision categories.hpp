//
//  collision categories.hpp
//  Buttons
//
//  Created by Indi Kernick on 7/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef collision_categories_hpp
#define collision_categories_hpp

#include <Simpleton/Utils/type list.hpp>
#include <Simpleton/Utils/instance limiter.hpp>

#define CATEGORIES                                                              \
  CAT(Default)                                                                  \
  CAT(PlayerBody)                                                               \
  CAT(ButtonTop)                                                                \
  CAT(ButtonBase)                                                               \
  LAST_CAT(Switch)

namespace Category {
  #define CAT(NAME) MAKE_SYMBOL(NAME);
  #define LAST_CAT(NAME) CAT(NAME)
  CATEGORIES
  #undef LAST_CAT
  #undef CAT
}

using Categories = Utils::TypeList<
  #define CAT(NAME) Category::NAME,
  #define LAST_CAT(NAME) Category::NAME
  CATEGORIES
  #undef LAST_CAT
  #undef CAT
>;

#undef CATEGORIES

static_assert(Utils::listSize<Categories> <= 16);

uint16_t getCategoryBit(const std::string &);

#endif
