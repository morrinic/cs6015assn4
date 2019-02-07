all: main

main: assignment3/assignment3/main.cpp
	clang++ assignment3/assignment3/main.cpp -o main

test: main
	./test2.sh
	
clean:
	rm -f main

fuzzer:
	clang++ -std=c++11 -c random_testing/quadrilateral_generator/general_quad.cpp random_testing/quadrilateral_generator/kite_generator.cpp 
	clang++ -std=c++11 -c random_testing/quadrilateral_generator/parallelogram_generator.cpp random_testing/quadrilateral_generator/rectangle_generator.cpp 
	clang++ -std=c++11 -c random_testing/quadrilateral_generator/rhombus_generator.cpp random_testing/quadrilateral_generator/square_generator.cpp 
	clang++ -std=c++11 -c random_testing/quadrilateral_generator/trapezoid_generator.cpp random_testing/quadrilateral_generator/quadrilateral_generator.cpp
	clang++ -std=c++11 -c random_testing/quad_error_generator/general_error.cpp random_testing/quad_error_generator/error_1_generator.cpp
	clang++ -std=c++11 -c random_testing/quad_error_generator/error_2_generator.cpp
	clang++ -o square general_quad.o square_generator.o
	clang++ -o rectangle general_quad.o rectangle_generator.o
	clang++ -o rhombus general_quad.o rhombus_generator.o
	clang++ -o parallelogram general_quad.o parallelogram_generator.o
	clang++ -o trapezoid general_quad.o trapezoid_generator.o
	clang++ -o kite general_quad.o kite_generator.o
	clang++ -o quadrilateral general_quad.o quadrilateral_generator.o
	clang++ -o error1 general_error.o error_1_generator.o
	clang++ -o error2 general_error.o error_2_generator.o

coverage:
	clang++ -fprofile-instr-generate -fcoverage-mapping assignment3/assignment3/main.cpp -o main
	LLVM_PROFILE_FILE="main.profraw" ./main < txt_files/test_data.txt
	-LLVM_PROFILE_FILE="error1_add.profraw" ./main < txt_files/error1_add_points.txt
	-LLVM_PROFILE_FILE="error1_sub.profraw" ./main < txt_files/error1_sub_points.txt 
	-LLVM_PROFILE_FILE="error1_high.profraw" ./main < txt_files/error1_high_point.txt
	-LLVM_PROFILE_FILE="error1_low.profraw" ./main < txt_files/error1_low_point.txt
	-LLVM_PROFILE_FILE="error1_letter.profraw" ./main < txt_files/error1_letter_point.txt
	-LLVM_PROFILE_FILE="error2_point.profraw" ./main < txt_files/error2_point_collision.txt
	-LLVM_PROFILE_FILE="error3_point.profraw" ./main < txt_files/error3_line_collision.txt
	-LLVM_PROFILE_FILE="error4_collinear.profraw" ./main < txt_files/error4_collinear.txt
	xcrun llvm-profdata merge -sparse main.profraw error1_add.profraw error1_sub.profraw error1_high.profraw error1_low.profraw error1_letter.profraw error2_point.profraw error3_point.profraw error4_collinear.profraw -o main.profdata
	xcrun llvm-cov show ./main -instr-profile=main.profdata