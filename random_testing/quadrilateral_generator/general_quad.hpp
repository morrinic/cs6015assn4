//
//  general.hpp
//  quadrilateral_generator
//
//  Created by Nicole Morris on 2/6/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#ifndef general_quad_hpp
#define general_quad_hpp

#include <stdio.h>
#include <string>

//Stores (x,y) point values
struct Point {int x; int y;};

//Helper fxn: generates string
std::string to_string(const Point& b, const Point& c, const Point& d);

//Generate random percent (decimal between 0 - 1)
double randomPercent();

//Generate random boolean
bool randomBoolean();

//Generates random int between 1 - 3
int random_max_3();

//Generates random int between 1 - 4
int random_max_4();

//Generates random int between 1 - 8
int random_max_8();

//Generates random int between 1 - 33
int random_max_33();

//Generates random int between 1 - 50
int random_max_50();

//Generates random int between 1 - 100
int random_max_100();

#endif /* general_quad_hpp */
