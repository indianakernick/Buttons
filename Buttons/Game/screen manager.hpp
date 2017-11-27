//
//  screen manager.hpp
//  Buttons
//
//  Created by Indi Kernick on 27/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef screen_manager_hpp
#define screen_manager_hpp

#include <memory>
#include "screen.hpp"
#include <unordered_map>

class ScreenManager {
public:
  ScreenManager() = default;
  
  template <typename Class, typename ...Args>
  void addScreen(Args &&... args) {
    std::unique_ptr<Screen> screen = std::make_unique<Class>(std::forward<Args>(args)...);
    const ScreenID id = screen->getID();
    current = screen.get();
    screens.emplace(id, std::move(screen));
  }
  void removeAll();
  void transition();
  
  void initAll(RenderingContext &);
  void quitAll();
  void input(const SDL_Event &);
  void update(float);
  glm::mat3 preRender(glm::ivec2, float);
  void render(NVGcontext *, float);
  
private:
  std::unordered_map<ScreenID, std::unique_ptr<Screen>> screens;
  Screen *current = nullptr;
};

#endif
