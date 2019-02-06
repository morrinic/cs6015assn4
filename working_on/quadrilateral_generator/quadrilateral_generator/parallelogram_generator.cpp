//
//  parallelogram_generator.cpp
//  quadrilateral_generator
//
//  Created by Nicole Morris on 2/5/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#include "parallelogram_generator.hpp"
#include "general.hpp"
#include <fstream>

//Driver fxn: returns string of 3 points for parallelogram (assumes point a is 0,0)
std::string generate_parallelogram(){
    
    Point b,c,d;
    bool randBool = randomBoolean();
    
    //Generate wide parallelogram
    if(randBool){
        
        b = {2,0};
        c = {3,1};
        d = {1,1};
        
    //Generate tall parallelogram
    } else {
        b = {1,1};
        c = {1,3};
        d = {0,2};
    }
    
    int random = random_max_33();
    
    b.x *= random;
    b.y*= random;
    c.x *= random;
    c.y *= random;
    d.x *= random;
    d.y *= random;
    
    return to_string(b,c,d);
    
}

//Driver fxn: outputs a set number of parallelogram to a file
void generate_parallelograms(int amount){
    
    //Create outstream of data.
    std::ofstream outFile("parallelogram.txt");
    
    for(int i = 0; i < amount; i++){
        outFile << generate_parallelogram() << "\n";
    }
    
}

int main(int argc, const char * argv[]) {
    generate_parallelograms(1);
}

