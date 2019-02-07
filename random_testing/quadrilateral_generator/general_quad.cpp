//
//  general.cpp
//  quadrilateral_generator
//
//  Created by Nicole Morris on 2/6/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#include "general_quad.hpp"

#include <cstdlib>

//Helper fxn: generates string
std::string to_string(const Point& b, const Point& c, const Point& d){
    std::string square = std::to_string(b.x) + " " + std::to_string(b.y);
    square = square + " " + std::to_string(c.x) + " " + std::to_string(c.y);
    square = square + " " + std::to_string(d.x) + " " + std::to_string(d.y);
    return square;
}

double randomPercent(){
    double percent = rand() % 100;
    return percent / 100.0;
}

int random_max_3(){
    return rand() % 3 + 1;
}

int random_max_4(){
    return rand() % 4 + 1;
}

int random_max_8(){
    return rand() % 8 + 1;
}

int random_max_33(){
    return rand() % 33 + 1;
}

int random_max_50(){
    return rand() % 50 + 1;
}

int random_max_100(){
    return rand() % 100 + 1;
}

bool randomBoolean(){
    
    if(rand() % 2 == 0){
        return true;
    }
    
    return false;
    
}
