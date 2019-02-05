./main < txt_files/dart.txt | grep 'dart' &&
./main < txt_files/kite1.txt | grep 'kite' &&
./main < txt_files/quad.txt | grep 'quadrilateral' &&
./main < txt_files/rectangle.txt | grep 'rectangle' &&
./main < txt_files/rhombus.txt | grep 'rhombus' &&
./main < txt_files/square.txt | grep 'square' &&
./main < txt_files/trapezoid1.txt | grep 'trapezoid' &&
./main < txt_files/trapezoid2.txt | grep 'trapezoid' &&
./main < txt_files/error1_add_points.txt | grep 'error 1' &&
./main < txt_files/error1_sub_points.txt | grep 'error 1' &&
./main < txt_files/error1_high_point.txt | grep 'error 1' &&
./main < txt_files/error1_low_point.txt | grep 'error 1' &&
./main < txt_files/error1_letter_point.txt | grep 'error 1' &&
./main < txt_files/error2_point_collision.txt | grep 'error 2' &&
./main < txt_files/error3_line_collision.txt | grep 'error 3' &&
./main < txt_files/error4_collinear.txt | grep 'error 4'
