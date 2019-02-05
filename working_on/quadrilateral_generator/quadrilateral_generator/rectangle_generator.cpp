//
//  rectangle_generator.cpp
//  quadrilateral_generator
//
//  Created by Nicole Morris on 2/5/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#include "quadrilateral_generator.hpp"
#include "rectangle_generator.hpp"

//Helper fxn: modifies points based on random number
void modifyRectangle(double& random, Point& b, Point& c, Point& d){
    
    b.x = b.x * random;
    c.x = c.x * random;
    c.y = c.y * random;
    d.y = d.y * random;
    
}

//Driver fxn: returns string of 3 points for rectangle (assumes point a is 0,0)
std::string generate_rectangle(){
    
    Point b,c,d;
    
    //Generate wide rectangle
    if(randomBoolean()){
        
        b = {100,0};
        c = {100,99};
        d = {0,99};
        
    //Generate tall rectangle
    } else {
        b = {99,0};
        c = {99,100};
        d = {0,100};
    }
    
    //Generate random percentage
    double random = randomPercent();
    
    //Modify points based on random percentage
    modifyRectangle(random,b,c,d);
    
    return to_string(b,c,d);
}
