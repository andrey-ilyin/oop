directives = -std=gnu++11
#boost_libs = -L"C:/sdk/boost_1_57_0/libs"
boost_incs = -I"C:/sdk/boost_1_57_0"

vector :
	g++ -o vector.exe $(boost_incs) Vector/main.cpp $(directives)

utest :
	g++ -o utest.exe $(boost_incs) VectorTest/VectorTest.cpp $(directives)

clean :
	rm -f vector.exe utest.exe
