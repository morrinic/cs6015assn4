all: main

main: main.cpp
	clang++ main.cpp

test: main
	./test.sh

run: main
	./a.out
	
clean:
	rm -f main
	rm -f a.out