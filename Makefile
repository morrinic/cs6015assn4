all: main

main: main.cpp
	clang++ main.cpp -o main

test: main
	./test2.sh
	
clean:
	rm -f main