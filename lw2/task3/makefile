directives = -std=c++11

multmatrix : matrix3.o
	g++ -o multmatrix.exe matrix3.o main.cpp $(directives)

matrix3.o :
	g++ -c matrix3.cpp $(directives)

clean :
	rm -f multmatrix.exe matrix3.o
