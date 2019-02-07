//
//  main.cpp
//  quadrilateral_generator
//
//  Created by Nicole Morris on 2/5/19.
//  Copyright © 2019 Nicole Morris. All rights reserved.
//

#include "quadrilateral_generator.hpp"
#include "square_generator.hpp"
#include "rectangle_generator.hpp"
#include "rhombus_generator.hpp"
#include "parallelogram_generator.hpp"
#include "trapezoid_generator.hpp"
#include "kite_generator.hpp"
#include "general_quad.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    //Generate text files with a 100 samples for each type
    generate_squares(100);
    generate_rectangles(100);
    generate_rhombi(100);
    generate_parallelograms(100);
    generate_trapezoids(100);
    generate_kites(100);
    generate_quadrilaterals(100);
    
    return 0;
    
}
