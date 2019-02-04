all: main

main: main.cpp
	clang++ main.cpp -o main

test: main
	./test2.sh
	
clean:
	rm -f main

coverage:
	clang++ -fprofile-instr-generate -fcoverage-mapping main.cpp -o main
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