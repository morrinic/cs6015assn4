#Compile all source code (update any changes)
clang++ -std=c++11 -c quadrilateral_generator/general.cpp quadrilateral_generator/kite_generator.cpp quadrilateral_generator/parallelogram_generator.cpp 
clang++ -std=c++11 -c quadrilateral_generator/rectangle_generator.cpp quadrilateral_generator/rhombus_generator.cpp quadrilateral_generator/square_generator.cpp 
clang++ -std=c++11 -c quadrilateral_generator/trapezoid_generator.cpp quadrilateral_generator/quadrilateral_generator.cpp 

#Link files to generate executables (update any changes)
clang++ -o square general.o square_generator.o
clang++ -o rectangle general.o rectangle_generator.o
clang++ -o rhombus general.o rhombus_generator.o
clang++ -o parallelogram general.o parallelogram_generator.o
clang++ -o trapezoid general.o trapezoid_generator.o
clang++ -o kite general.o kite_generator.o
clang++ -o quadrilateral general.o quadrilateral_generator.o

#Generate & test quadrilaterals for correct classification
for i in {1..100}; do
    ./square 
    ./main < square.txt | grep 'square'
done

for i in {1..100}; do
    ./rectangle 
    ./main < rectangle.txt | grep 'rectangle'
done

for i in {1..100}; do
    ./rhombus 
    ./main < rhombus.txt | grep 'rhombus'
done

for i in {1..100}; do
    ./parallelogram 
    ./main < parallelogram.txt | grep 'parallelogram'
done

for i in {1..100}; do
    ./trapezoid 
    ./main < trapezoid.txt | grep 'trapezoid'
done

for i in {1..100}; do
    ./kite 
    ./main < kite.txt | grep 'kite'
done

for i in {1..100}; do
    ./quadrilateral 
    ./main < quadrilateral.txt | grep 'quadrilateral' || grep 'square' || grep 'rectangle' || grep 'rhombus' || grep 'parallelogram' || grep 'trapezoid' || grep 'kite'
done
