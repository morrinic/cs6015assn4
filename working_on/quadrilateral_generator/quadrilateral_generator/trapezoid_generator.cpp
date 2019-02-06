//
//  trapezoid_generator.cpp
//  quadrilateral_generator
//
//  Created by Nicole Morris on 2/6/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#include "trapezoid_generator.hpp"
#include "general.hpp"
#include <fstream>

void makeWideTrapezoid(Point &b, Point &c, Point &d){
    
    int random_four = random_max_4();
    
    if(random_four==1){
        d.y += 1;
        
    } else if(random_four==2){
        c.y += 1;
        
    } else if(random_four==3){
        c.x -= 1;
        
    } else {
        b.x -= 1;
    }
    
}

void makeTallTrapezoid(Point &b, Point &c, Point &d){
    
    int random_four = random_max_4();
    
    if(random_four==1){
        d.y -= 1;
        
    } else if(random_four==2){
        c.y -= 1;
        
    } else if(random_four==3){
        c.x += 1;
        
    } else {
        b.x += 1;
    }
    
}

//Driver fxn: returns string of 3 points for trapezoid (assumes point a is 0,0)
std::string generate_trapezoid(){
    
    Point b,c,d;
    
    if(randomBoolean()){
        
        //Generate wide rectangle
        b = {2,0};
        c = {2,1};
        d = {0,1};
        
        makeWideTrapezoid(b,c,d);
        
    } else {
        
        //Generate tall rectangle
        b = {1,0};
        c = {1,2};
        d = {0,2};
        
        makeTallTrapezoid(b,c,d);

    }
    
    int random = random_max_50();
    
    b.x *= random;
    b.y*= random;
    c.x *= random;
    c.y *= random;
    d.x *= random;
    d.y *= random;
    
    return to_string(b,c,d);
    
}

//Driver fxn: outputs a set number of trapezoids to a file
void generate_trapezoids(int amount){
    
    //Create outstream of data.
    std::ofstream outFile("trapezoid.txt");
    
    for(int i = 0; i < amount; i++){
        outFile << generate_trapezoid() << "\n";
    }
    
}

int main(int argc, const char * argv[]) {
    generate_trapezoids(1);
}

