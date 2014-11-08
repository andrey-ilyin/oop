directives = -std=c++11

multmatrix : matrix3.o
	g++ -o multmatrix matrix3.o main.cpp $(directives)

matrix3.o :
	g++ -c matrix3.cpp $(directives)

clean :
	rm multmatrix matrix3.o
