directives = -std=gnu++11
#boost_libs = -L"C:/sdk/boost_1_57_0/libs"
boost_incs = -I"C:/sdk/boost_1_57_0"
main_incs = -I"."
main_dir = PrimeNumbers
test_dir = PrimeNumbersTest

prime : PrimeNumbers.o
	g++ -o prime.exe PrimeNumbers.o $(boost_incs) $(main_dir)/main.cpp $(directives)

PrimeNumbers.o :
	g++ -c $(main_dir)/PrimeNumbers.cpp $(directives)

utest : PrimeNumbers.o
	g++ -o utest.exe PrimeNumbers.o $(boost_incs) $(main_incs) $(test_dir)/PrimeNumbersTest.cpp $(directives)

clean :
	rm -f *.o *.exe
