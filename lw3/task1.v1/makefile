directives = -std=gnu++11
#boost_libs = -L"C:/sdk/boost_1_57_0/libs"
boost_incs = -I"C:/sdk/boost_1_57_0"
Vector_incs = -I"."

vector : VectorProcessor.o
	g++ -o vector.exe VectorProcessor.o $(boost_incs) Vector/main.cpp $(directives)

VectorProcessor.o :
	g++ -c Vector/VectorProcessor.cpp $(directives)

utest : VectorProcessor.o
	g++ -o utest.exe VectorProcessor.o $(boost_incs) $(Vector_incs) VectorTest/VectorTest.cpp $(directives)

clean :
	rm -f vector.exe utest.exe VectorProcessor.o
