//
//  error_2_generator.cpp
//  quad_error_generator
//
//  Created by Nicole Morris on 2/6/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#include "error_2_generator.hpp"
#include "general.hpp"
#include <fstream>

std::string generate_error_2(){
    
    Point b = {1,0};
    Point c = {1,1};
    Point d = {0,1};
    
    int boolean = random_max_3();
    
    if(boolean == 1){
        
        //ab same
        b = {0,0};
        
    } else if(boolean == 2){
        
        //bc same
        c = {1,0};
        
    } else if(boolean == 2){
        
        //cd same
        d = {1,1};
        
    } else {
        
        //da same
        d = {0,0};
    }
    
    return pts_to_string(b,c,d);
    
}

void generate_error_2s(int amount){
    
    //Create outstream of data.
    std::ofstream outFile("error_2.txt");
    
    for(int i = 0; i < amount-1; i++){
        outFile << generate_error_2() << "\n";
    }
    
    outFile << generate_error_2();
    
}

int main(int argc, const char * argv[]) {
    generate_error_2s(1);
}
