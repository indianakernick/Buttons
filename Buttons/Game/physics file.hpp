//
//  physics file.hpp
//  Buttons
//
//  Created by Indi Kernick on 1/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef physics_file_hpp
#define physics_file_hpp

#include "json helper.hpp"
#include "transform component.hpp"
#include "../Libraries/Box2D/Box2D.h"

b2Body *loadBody(const std::string &, b2World &, Transform);
void readJoint(b2JointDef *, const json &);
b2JointDef *loadJoint(const std::string &);


#endif
