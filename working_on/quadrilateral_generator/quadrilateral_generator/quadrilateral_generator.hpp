//
//  quadrilateral_generator.hpp
//  quadrilateral_generator
//
//  Created by Nicole Morris on 2/5/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#ifndef quadrilateral_generator_hpp
#define quadrilateral_generator_hpp

#include <stdio.h>
#include <string>

struct Point {int x; int y;};
struct Angle {Point a; Point b; Point c; float degrees;};
struct Quad {float ab; float bc; float cd; float da; Angle a; Angle b; Angle c; Angle d;};

//Generate random percent (decimal between 0 - 1)
double randomPercent();

//Generate random boolean
bool randomBoolean();

//Generates random int between 1 - 3
int random_max_3();

//Generates random int between 1 - 8
int random_max_8();

//Generates random int between 1 - 33
int random_max_33();

//Helper fxn: generates string
std::string to_string(const Point& b, const Point& c, const Point& d);

#endif /* quadrilateral_generator_hpp */
