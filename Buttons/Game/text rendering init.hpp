//
//  text rendering init.hpp
//  Buttons
//
//  Created by Indi Kernick on 22/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef text_rendering_init_hpp
#define text_rendering_init_hpp

#include "comp init.hpp"
#include "text rendering component.hpp"

class TextRenderingInit final : public CompInit<TextRendering> {
public:
  explicit TextRenderingInit(const Unpack::Spritesheet &);

  void init(TextRendering &, const json &) override;

private:
  const Unpack::Spritesheet &sheet;
};

#endif
