all: main

main: main.cpp
	clang++ main.cpp -o main

test: main
	./test2.sh
	
clean:
	rm -f main

matrix:
  include:
    - os: osx
      osx_image: xcode10.1
    
    - os: osx
      osx_image: xcode9.4