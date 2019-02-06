//
//  square_generator.cpp
//  quadrilateral_generator
//
//  Created by Nicole Morris on 2/5/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#include "square_generator.hpp"
#include "general.hpp"

//Helper fxn: modifies points based on random number
void modifySquare(double& random, Point& b, Point& c, Point& d){
    
    b.x = b.x * random;
    c.x = c.x * random;
    c.y = c.y * random;
    d.y = d.y * random;
    
}

//Driver fxn: returns string of 3 points for square (assumes point a is 0,0)
std::string generate_square(){
    
    //Seed points for square that is 100% of maximum size
    Point b = {100,0};
    Point c = {100,100};
    Point d = {0,100};
    
    //Generate random percentage
    double random = randomPercent();
    
    //Modify points based on random percentage
    modifySquare(random,b,c,d);
    
    return to_string(b,c,d);
}

