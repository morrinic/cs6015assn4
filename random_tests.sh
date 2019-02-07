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
