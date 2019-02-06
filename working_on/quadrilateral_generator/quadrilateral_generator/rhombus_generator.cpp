//
//  rhombus_generator.cpp
//  quadrilateral_generator
//
//  Created by Nicole Morris on 2/5/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#include "quadrilateral_generator.hpp"
#include "general.hpp"
#include <fstream>

//Helper fxn: modifies points based on random number
void modifyRhombus(double& random, Point& b, Point& c, Point& d){
    
    b.x = b.x * random;
    b.y = b.y * random;
    
    c.x = c.x * random;
    c.y = c.y * random;
    
    d.x = d.x * random;
    d.y = d.y * random;
    
}

//Helper fxn: generates random rhombus seed
void randomSeed(Point &b, Point &c, Point &d){
    
    if(randomBoolean()){
        b = {5,5};
        c = {6,12};
        d = {1,7};
    } else {
        b = {5,0};
        c = {8,4};
        d = {3,4};
    }
}

//Driver fxn: returns string of 3 points for rhombus (assumes point a is 0,0)
std::string generate_rhombus(){
    
    //Seed points for a small rhombus
    Point b;
    Point c;
    Point d;
    
    randomSeed(b,c,d);
    
    //Generate random growth integer
    double random = random_max_8();
    
    //Modify points based on random percentage
    modifyRhombus(random,b,c,d);
    
    return to_string(b,c,d);
}

//Driver fxn: outputs a set number of rhombi to a file
void generate_rhombi(int amount){
    
    //Create outstream of data.
    std::ofstream outFile("rhombus.txt");
    
    for(int i = 0; i < amount; i++){
        outFile << generate_rhombus() << "\n";
    }
    
}

int main(int argc, const char * argv[]) {
    generate_rhombi(1);
}

