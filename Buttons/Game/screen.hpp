//
//  screen.hpp
//  Buttons
//
//  Created by Indi Kernick on 26/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef screen_hpp
#define screen_hpp

#include <glm/vec2.hpp>
#include <glm/mat3x3.hpp>

class RenderingContext;
extern "C" union SDL_Event;
extern "C" struct NVGcontext;

class Screen {
public:
  Screen() = default;
  virtual ~Screen() = default;
  
  virtual void enter() = 0;
  virtual void leave() = 0;
  
  virtual void init(RenderingContext &) = 0;
  virtual void quit() = 0;
  virtual void input(const SDL_Event &) = 0;
  virtual void update(float) = 0;
  virtual glm::mat3 preRender(glm::ivec2, float) = 0;
  virtual void render(NVGcontext *, float) = 0;
};

#endif
