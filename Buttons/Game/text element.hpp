//
//  text element.hpp
//  Buttons
//
//  Created by Indi Kernick on 27/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef text_element_hpp
#define text_element_hpp

#include <string>
#include "element.hpp"

class TextElement final : public Element {
public:
  TextElement() = default;
  
  void text(const std::string &);
  std::string text() const;
  
  void nullFont();
  
  void render(SDL_Renderer *) const override;
  
private:
  std::string mText;
};

#endif
