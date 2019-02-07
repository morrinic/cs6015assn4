//
//  error_1_generator.cpp
//  quad_error_generator
//
//  Created by Nicole Morris on 2/6/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#include "error_1_generator.hpp"
#include "general_error.hpp"
#include <fstream>
#include <vector>
#include <string>

std::string range_error(std::vector<Point> &points){
    
    int random = random_max_6();
    int rand_int = rand();
    while(rand_int >= 1 && rand_int <= 100){
        rand_int = rand();
    }
    
    if(random == 0){
        return std::to_string(random_max_100()) + " 0 1 1 0 1";
    } else if(random == 1){
        return "1 " + std::to_string(rand_int) + " 1 1 0 1";
    } else if(random == 2){
        return "1 0 " + std::to_string(rand_int) + " 1 0 1";
    } else if(random == 3){
        return "1 0 1 " + std::to_string(rand_int) + " 0 1";
    } else if(random == 4){
        return "1 0 1 1 " + std::to_string(rand_int) + " 1";
    } else {
        return "1 0 1 1 0 " + std::to_string(rand_int);
    }
    
}
std::string inv_char_error(){

    int random = random_max_6();

    if(random == 0){
        return random_character() + " 0 1 1 0 1";
    } else if(random == 1){
        return "1 " + random_character() + " 1 1 0 1";
    } else if(random == 2){
        return "1 0 " + random_character() + " 1 0 1";
    } else if(random == 3){
        return "1 0 1 " + random_character() + " 0 1";
    } else if(random == 4){
        return "1 0 1 1 " + random_character() + " 1";
    } else {
        return "1 0 1 1 0 " + random_character();
    }
    
}

std::string pt_num_error(std::vector<Point> &points){
    
    int random = random_max_8();
    
    //Error only occurs if there aren't 3 points
    while(random == 3){
        random = random_max_8();
    }
    
    for(int i = 0; i < random; i++){
        
        int rand_x = random_max_100();
        int rand_y = random_max_100();
        points.push_back({rand_x,rand_y});
        
    }
    
    return vpts_to_string(points);
    
}

std::string generate_error_1(){

    std::vector<Point> points;
    std::string result;
    
    int boolean = random_max_3();

    if(boolean == 1){
    
        //Generate wrong number points
        return pt_num_error(points);
        
    } else if(boolean == 2){

        //Generate invalid characters
        return inv_char_error();
        
    } else {
    
        //Generate out of range
        return range_error(points);
    }
    
}

void generate_error_1s(int amount){
    
    //Create outstream of data.
    std::ofstream outFile("error_1.txt");
    
    for(int i = 0; i < amount-1; i++){
        outFile << generate_error_1() << "\n";
    }
    
    outFile << generate_error_1();
    
}

int main(int argc, const char * argv[]) {
    generate_error_1s(1);
}
