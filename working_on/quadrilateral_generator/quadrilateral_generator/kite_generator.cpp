//
//  kite_generator.cpp
//  quadrilateral_generator
//
//  Created by Nicole Morris on 2/6/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#include "kite_generator.hpp"
#include "general.hpp"

//Driver fxn: returns string of 3 points for kite (assumes point a is 0,0)
std::string generate_kite(){
    
    Point b = {30,90};
    Point c = {100,100};
    Point d = {90,30};
    
    if(randomBoolean()){
        
        //Convert to dart (kite with inverted tip)
        c = {45,45};
        
    }
    
    //Generate random percentage
    double random = randomPercent();
    
    b.x = b.x * random;
    c.x = c.x * random;
    c.y = c.y * random;
    d.y = d.y * random;

    return to_string(b,c,d);
}

