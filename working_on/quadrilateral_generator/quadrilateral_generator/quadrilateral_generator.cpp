//
//  quadrilateral_generator.cpp
//  quadrilateral_generator
//
//  Created by Nicole Morris on 2/5/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#include "quadrilateral_generator.hpp"

#include <cstdlib>

double randomPercent(){
    double percent = rand() % 100;
    return percent / 100.0;
}

int randomInteger(){
    return rand() % 8 + 1;
}

bool randomBoolean(){
    
    if(rand() % 2 == 0){
        return true;
    }
    
    return false;
    
}

//Helper fxn: generates string
std::string to_string(const Point& b, const Point& c, const Point& d){
    std::string square = std::to_string(b.x) + " " + std::to_string(b.y);
    square = square + " " + std::to_string(c.x) + " " + std::to_string(c.y);
    square = square + " " + std::to_string(d.x) + " " + std::to_string(d.y);
    return square;
}

