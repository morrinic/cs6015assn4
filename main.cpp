//
//  main.cpp
//  assignment3
//
//  Created by Nicole Morris on 1/16/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <sstream>

struct Point {int x; int y;};
struct Angle {Point a; Point b; Point c; float degrees;};
struct Quad {float ab; float bc; float cd; float da; Angle a; Angle b; Angle c; Angle d;};

/*
 * MATH FXNS
 * Used to find components quadrilateral features (side length, angle degrees, side slope)
 */

//Calculates the length of a line between 2 xy coordinates
//Modified from www.geeksforgeeks.org/program-calculate-distance-two-points/
float calcLength(Point a, Point b){
    
    return sqrt(pow(b.x - a.x,2) + pow(b.y-a.y,2));
}

//Calculates the value of degress based on 3 xy coordinates
//Modified from www.geeksforgeeks.org/find-angles-given-triangle/
float calcDeg(Point a, Point b, Point c){
    
    double pi = 3.1415926535;
    float sideAB = calcLength(a,b);
    float sideBC = calcLength(b,c);
    float sideCA = calcLength(c,a);
    
    return (180 / pi * (acos((pow(sideAB,2) + pow(sideBC,2) - pow(sideCA,2)) / (2 * sideAB * sideBC))));
    
}

//Calculates the slope of a line
//Modified from www.geeksforgeeks.org/program-find-slope-line/
float slope(float ax, float ay, float bx, float by){
    
    return (by - ay) / (bx - ax);
    
}

/*
 * CLASSIFICATION FXNS
 * Determines the type of quadrilateral (square, rhombus, rectangle, parallelogram, kite, trapezoid, quadrilateral)
 */

//Determines if a quadrilateral is a parallelogram
bool isParallel(Quad quad){
    
    //Opposite sides are congruent
    if(quad.ab == quad.cd && quad.bc == quad.da){
        return true;
    }
    
    return false;
}

//Determines if a parallelogram is a rhombus
bool isRhombus(Quad quad){
    
    if(quad.ab == quad.bc){
        if(quad.bc == quad.cd){
            if(quad.cd == quad.da){
                if(quad.da == quad.ab){
                    return true;
                }
            }
            
        }
    }
    return false;
}

//Determines if a parallelogram is a rectangle
bool isRectangle(Quad quad){
    
    if(quad.a.degrees == quad.b.degrees){
        if(quad.b.degrees == quad.c.degrees){
            if(quad.c.degrees == quad.d.degrees){
                if(quad.d.degrees == quad.a.degrees){
                    return true;
                }
            }
        }
    }
    
    return false;
}

//Determines if a rhombus or rectangle is a square
bool isSquare(Quad quad){
    
    //Already classified as a rhombus so...
    return isRectangle(quad);
    
}

//Determines if a quadrilateral is a kite
bool isKite(Quad quad){
    
    if((quad.ab == quad.bc && quad.cd == quad.da) || (quad.ab == quad.da && quad.bc == quad.cd)){
        return true;
    }
    return false;
}

//Determines if a quadrilateral is a trapezoid
bool isTrapezoid(Quad quad){
    
    if(slope(quad.a.b.x,quad.a.b.y,quad.b.b.x,quad.b.b.y) == slope(quad.d.b.x,quad.d.b.y,quad.c.b.x,quad.c.b.y)){
        if(!(slope(quad.b.b.x,quad.b.b.y,quad.c.b.x,quad.c.b.y) == slope(quad.a.b.x,quad.a.b.y,quad.d.b.x,quad.d.b.y))){
            return true;
        }
    } else if (slope(quad.b.b.x,quad.b.b.y,quad.c.b.x,quad.c.b.y) == slope(quad.a.b.x,quad.a.b.y,quad.d.b.x,quad.d.b.y)){
        if(!(slope(quad.a.b.x,quad.a.b.y,quad.b.b.x,quad.b.b.y) == slope(quad.d.b.x,quad.d.b.y,quad.c.b.x,quad.c.b.y))){
            return true;
        }
    }
    
    return false;
    
}

//Prints the classification of a parallelogram
void classifyParallel(Quad quad){
    //If parallelogram, determine if rhombus
    if(isRhombus(quad)){
        
        //If rhombus, determine if square
        if(isSquare(quad)){
            std:: cout << "square" << std::endl;
        } else {
            std:: cout << "rhombus" << std::endl;
        }
        
    } else {
        //Confirm is a rectangle
        
        if(isRectangle(quad)){
            std:: cout << "rectangle" << std::endl;
            
        } else {
            
            //If not rhombus or rectangle...
            std:: cout << "parallelogram" << std::endl;
            
        }
    }
}

//Prints the classification of a quadrilateral that is not a parallelogram
void classifyNotParallel(Quad quad){
    if(isKite(quad)){
        std::cout << "kite" << std::endl;
    } else if(isTrapezoid(quad)){
        std::cout << "trapezoid" << std::endl;
    } else {
        std::cout << "quadrilateral" << std::endl;
    }
}

//Prints the classification of a quadrilateral
void classifyQuad(Quad quad){
    
    //Determine if parallelogram
    if(isParallel(quad)){
        classifyParallel(quad);
    } else {
        
        classifyNotParallel(quad);
    }
}

/*
 * ERROR CHECKING FUNCTIONS
 */

void error(std::string message){
    std::cout << message << std::endl;
    exit(1);
}

void checkLength(std::vector<std::string> lines){
    
    static int length = lines.size();
    
    //Check number of points
    if(length < 6 | length > 6){
        error("error 1");
    }
    
}

void checkRange(int digits[6]){
    
    for(int i = 0; i < 6; i++){
        if(digits[i] < 0| digits[i] >100){
            error("error 1");
        }
    }
    
}

int convertToDigit(std::string value){
    
    if(!isdigit(value.at(0))){
        error("error 1");
    }
    
    int digit = atoi(&value.at(0));
    
    //Check range
    if( digit < 0 | digit > 100){
        error("error 1");
    }
    
    return digit;
    
}

void checkForErrors(Point a, Point b, Point c, Point d){
    
    
    //    checkCollisions(a,b,c,d);
    //
    //    checkThree(a,b,c,d);
    //
    //    checkFour(a,b,c,d);
    
}

std::vector<std::string> parseLine(std::string line){
    
    std::stringstream ss(line);
    std::string value;
    std::vector<std::string> parsed;
    while (std::getline(ss, value, ' '))
    {
        parsed.push_back(value);
    }
    
    checkLength(parsed);
    
    return parsed;
    
}

/*
 * DATA INPUT FXNS
 * Stores user inputted quadrilateral data
 */

//Stores a quadrilateral
Quad storeQuad(Point a, Point b, Point c, Point d){
    
    Angle angA = {d,a,b, calcDeg(d,a,b)};
    Angle angB = {a,b,c, calcDeg(a,b,c)};
    Angle angC = {b,c,d, calcDeg(b,c,d)};
    Angle angD = {c,d,a, calcDeg(c,b,a)};
    
    Quad quad = {calcLength(a,b), calcLength(b,c), calcLength(c,d), calcLength(d,a), angA, angB, angC, angD};
    
    return quad;
    
}

//Stores input data
std::vector<Quad> storeInputData(){
    
    std::vector<Quad> data;
    
    while(!std::cin.eof()){
        
        //Input line
        std::string line;
        getline(std::cin, line);
        
        //Parse line
        std::stringstream ss(line);
        std::string value;
        std::vector<std::string> parsed;
        while (std::getline(ss, value, ' '))
        {
            parsed.push_back(value);
        }
        
        checkLength(parsed);
        
        //Convert to integers
        int digits[6];
        for(int i = 0; i < parsed.size(); i++){
            
            if(isdigit(parsed[i][0])){
                int digit = stoi(parsed[i]);
                digits[i] = digit;
            } else {
                error("error 1");
            }
        }
        
        checkRange(digits);
        
        Point a = {0,0};
        Point b = {digits[0],digits[1]};
        Point c = {digits[2],digits[3]};
        Point d = {digits[4],digits[5]};
        
        //Check points
        checkForErrors(a, b, c, d);
        
        data.push_back(storeQuad(a, b, c, d));
        
    }
    
    return data;
    
}

/*
 * MAIN
 */

int main(int argc, const char * argv[]) {
    
    //Store data points from file
    std::vector<Quad> data = storeInputData();
    
    //Classify each quadrilateral
    for(int i = 0; i < data.size(); i++){
        classifyQuad(data[i]);
    }
    
    return 0;
    
}
