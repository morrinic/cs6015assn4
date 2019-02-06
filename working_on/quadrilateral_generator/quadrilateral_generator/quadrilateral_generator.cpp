//
//  quadrilateral_generator.cpp
//  quadrilateral_generator
//
//  Created by Nicole Morris on 2/5/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#include "quadrilateral_generator.hpp"
#include "general.hpp"
#include <math.h>

//Helper fxn: Calculates the length of a line between 2 xy coordinates
//Modified from www.geeksforgeeks.org/program-calculate-distance-two-points/
double calcLength(const Point &a, const Point &b){
    return sqrt(pow(b.x - a.x,2) + pow(b.y-a.y,2));
}

//Helper fxn: returns area of a triangle
//Modified from www.geeksforgeeks.org/program-check-three-points-collinear
double calcTriArea(const Point &a, const Point &b, const Point &c){
    
        double AB = calcLength(a,b);
        double BC = calcLength(b,c);
        double CA = calcLength(c,a);
        
        
        if (AB < 0 || BC < 0 || CA <0 || (AB+BC <= CA) || AB+CA <=BC || BC+CA <=AB) {
            printf("Not a valid triangle\n");
            exit(0);
        }
        double s = (AB+BC+CA)/2.0;
        return sqrt(s*(s-AB)*(s-BC)*(s-CA));
        
//    return a.x * (b.y-c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

//Helper fxn: determines if 2 points are the same
bool isSamePoint(const Point &a, const Point &b){
    if(a.x == b.x && a.y == b.y){
        return true;
    }
    return false;
}

//Helper fxns: determine if 3 points are collinear
//Modified from www.geeksforgeeks.org/program-for-point-of-intersection-of-two-lines
bool isOnLine(const Point &a, const Point &b, const Point &intersect){
    
    double ax, bx, ay, by;
    
    //Determine max and min x values
    if(a.x >= b.x){
        ax = b.x;
        bx = a.x;
        
    } else {
        ax = a.x;
        bx = b.x;
    }
    
    //Determine max and min y values
    if(a.y >= b.y){
        ay = b.y;
        by = a.y;
        
    } else {
        ay = a.y;
        by = b.y;
    }
    
    //Determine if intersect is on line
    if(ax <= intersect.x && intersect.x <= bx && ay <= intersect.y && intersect.y <= by){
        return true;
    }
    
    return false;
}

//Modified from www.geeksforgeeks.org/program-for-point-of-intersection-of-two-lines
bool hasLineCollision(const Point &a, const Point &b, const Point &c, const Point &d){
    
    //Line AB = c1 = a1x + b1y
    double a1 = c.y - b.y;
    double b1 = b.x - c.x;
    double c1 = a1*(b.x) + b1*(b.y);
    
    //Line CD = c2 = a2x + b2y
    double a2 = a.y - d.y;
    double b2 = d.x - a.x;
    double c2 = a2*(d.x) + b2*(d.y);
    
    double determinant = a1*b2 - a2*b1;
    
    if(determinant != 0){
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        Point intersect = {static_cast<int>(x),static_cast<int>(y)};
        
        if(isOnLine(b,c,intersect) && isOnLine(d,a,intersect)){
            return true;
        }
        
    }
    
    return false;
    
}

//Driver fxn: returns string of 3 points for quadrilateral (assumes point a is 0,0)
std::string generate_quadrilateral(){
    
    Point a = {0,0};
    Point b = {random_max_100(), random_max_100()};
    Point c = {random_max_100(), random_max_100()};
    Point d = {random_max_100(), random_max_100()};
    
    if(isSamePoint(a,b) | isSamePoint(b,c) | isSamePoint(c,d) | isSamePoint(d,a)){
        return generate_quadrilateral();
    }
    
    if(calcTriArea(a,b,c) == 0 || calcTriArea(b,c,d) == 0 || calcTriArea(c,d,a) == 0 || calcTriArea(d,a,b) == 0){
           return generate_quadrilateral();
    }
    
    if(hasLineCollision(a,b,c,d)){
        return generate_quadrilateral();
    }
    
    
    return to_string(b,c,d);
}
