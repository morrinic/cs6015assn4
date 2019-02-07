//
//  general.cpp
//  quad_error_generator
//
//  Created by Nicole Morris on 2/6/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#include "general_error.hpp"

#include <cstdlib>
#include <vector>
#include <iostream>

//Helper fxn: generates string from points
std::string pt_to_string(const Point &p){
    return std::to_string(p.x) + " " + std::to_string(p.y) + " ";
}

std::string pts_to_string(const Point& b, const Point& c, const Point& d){
    std::string square = std::to_string(b.x) + " " + std::to_string(b.y);
    square = square + " " + std::to_string(c.x) + " " + std::to_string(c.y);
    square = square + " " + std::to_string(d.x) + " " + std::to_string(d.y);
    return square;
}

std::string vpts_to_string(const std::vector<Point> &points){
    
    std::string s;
    
    for(int i = 0; i < points.size() - 1; i++){
        s += pt_to_string(points.at(i)) + " ";
    }
    
    s += pt_to_string(points.at(points.size()-1));
    
    return s;
    
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

int random_max_6(){
    return rand() % 6 + 1;
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

int random_max_126(){
    return rand() % 126 + 1;
}

bool randomBoolean(){
    
    if(rand() % 2 == 0){
        return true;
    }
    
    return false;
    
}

std::string random_character(){
    char c = random_max_126();
    
    while(c < ':'){
        c = random_max_126();
    }
    
    std::string s;
    s.push_back(c);
    
    return s;
}
