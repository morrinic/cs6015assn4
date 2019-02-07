//
//  general.hpp
//  quad_error_generator
//
//  Created by Nicole Morris on 2/6/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#ifndef general_error_hpp
#define general_error_hpp

#include <stdio.h>
#include <string>

//Stores (x,y) point values
struct Point {int x; int y;};

//Helper fxn: generates string
std::string pt_to_string(const Point &p);
std::string pts_to_string(const Point& b, const Point& c, const Point& d);
std::string vpts_to_string(const std::vector<Point> &points);

//Generate random percent (decimal between 0 - 1)
double randomPercent();

//Generate random boolean
bool randomBoolean();

//Generates random int between 1 - 3
int random_max_3();

//Generates random int between 1 - 4
int random_max_4();

//Generates random int between 1 - 6
int random_max_6();

//Generates random int between 1 - 8
int random_max_8();

//Generates random int between 1 - 33
int random_max_33();

//Generates random int between 1 - 50
int random_max_50();

//Generates random int between 1 - 100
int random_max_100();

//Generates a random ascii character between 1 - 100
std::string random_character();

#endif /* general_error_hpp */
