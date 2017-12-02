//
//  text rendering init.cpp
//  Buttons
//
//  Created by Indi Kernick on 20/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "text rendering init.hpp"

TextRenderingInit::TextRenderingInit(RenderingResources &newResources)
  : resources(&newResources) {}

void TextRenderingInit::init(TextRendering &comp, const json &node) {
  comp.font = resources->getFont(node.at("font").get_ref<const std::string &>());
  comp.color = nvgRGBf(1.0f, 1.0f, 1.0f);
  getOptional(comp.color, node, "color");
  
  if (const auto alignNode = node.find("vert align"); alignNode != node.cend()) {
    const std::string &alignStr = alignNode->get_ref<const std::string &>();
           if (alignStr == "top") {
      comp.align = NVG_ALIGN_TOP;
    } else if (alignStr == "middle") {
      comp.align = NVG_ALIGN_MIDDLE;
    } else if (alignStr == "bottom") {
      comp.align = NVG_ALIGN_BOTTOM;
    } else if (alignStr == "baseline") {
      comp.align = NVG_ALIGN_BASELINE;
    }
  } else {
    comp.align = NVG_ALIGN_BASELINE;
  }
  
  if (const auto alignNode = node.find("hori align"); alignNode != node.cend()) {
    const std::string &alignStr = alignNode->get_ref<const std::string &>();
           if (alignStr == "left") {
      comp.align |= NVG_ALIGN_LEFT;
    } else if (alignStr == "center") {
      comp.align |= NVG_ALIGN_CENTER;
    } else if (alignStr == "right") {
      comp.align |= NVG_ALIGN_RIGHT;
    }
  } else {
    comp.align |= NVG_ALIGN_LEFT;
  }
  
  comp.size = 12.0f;
  getOptional(comp.size, node, "size");
}
