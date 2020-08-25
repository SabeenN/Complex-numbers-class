CC    = g++

FLAGS = -std=c++14 -g -Wall -Wunused-but-set-variable -pedantic

complex.out: complex.cpp
	$(CC) $(FLAGS) complex.cpp -o complex.out

all:
		/cxxtest/cxxtestgen.py --error-printer -o simple_testrunner.cpp ./cxxTests/simple.cxxtest.cpp
		$(CC) $(FLAGS) -c complex.cpp -o complex.out
		g++ -std=c++11 -o simple_test.out -I /cxxtest/ simple_testrunner.cpp complex.out
		./simple_test.out

clean:
	rm -f *.o *.out
