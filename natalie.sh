./a.out < txt_files/dart.txt | grep 'kite' &&
./a.out < txt_files/kite1.txt | grep 'kite' &&
./a.out < txt_files/quad.txt | grep 'quadrilateral' &&
./a.out < txt_files/rectangle.txt | grep 'rectangle' &&
./a.out < txt_files/rhombus.txt | grep 'rhombus' &&
./a.out < txt_files/square.txt | grep 'square' &&
./a.out < txt_files/trapezoid1.txt | grep 'trapezoid' &&
./a.out < txt_files/trapezoid2.txt | grep 'trapezoid' &&
./a.out < txt_files/error1_add_points.txt | grep 'error 1' &&
./a.out < txt_files/error1_sub_points.txt | grep 'error 1' &&
./a.out < txt_files/error1_high_point.txt | grep 'error 1' &&
./a.out < txt_files/error1_low_point.txt | grep 'error 1' &&
./a.out < txt_files/error1_letter_point.txt | grep 'error 1' &&
./a.out < txt_files/error2_point_collision.txt | grep 'error 2' &&
./a.out < txt_files/error3_line_collision.txt | grep 'error 3' &&
./a.out < txt_files/error4_collinear.txt | grep 'error 4'