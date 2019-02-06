//
//  rectangle_generator.hpp
//  quadrilateral_generator
//
//  Created by Nicole Morris on 2/5/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#ifndef rectangle_generator_hpp
#define rectangle_generator_hpp

#include <stdio.h>
#include <string>
#include "general.hpp"

//Returns string of 3 points for rectangle (assumes point a is 0,0)
std::string generate_rectangle();

//Helper fxn: modifies points based on random number
void modifyRectangle(double& random, Point &b, Point &c, Point &d);

#endif /* rectangle_generator_hpp */
