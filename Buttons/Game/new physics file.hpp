//
//  new physics file.hpp
//  Buttons
//
//  Created by Indi Kernick on 1/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef new_physics_file_hpp
#define new_physics_file_hpp

#include "json helper.hpp"
#include "transform component.hpp"
#include "../Libraries/Box2D/Box2D.h"

b2Body *loadBodyJSON(const std::string &, b2World &, Transform);
void readJointJSON(b2JointDef *, const json &);
b2JointDef *loadJointJSON(const std::string &);


#endif
