directives = -std=gnu++11
#boost_libs = -L"C:/sdk/boost_1_57_0/libs"
boost_incs = -I"C:/sdk/boost_1_57_0"
main_incs = -I"."
main_dir = TvSet
test_dir = TvSetTest

tvset : CTvSet.o
	g++ -o tvset.exe CTvSet.o $(boost_incs) $(main_dir)/main.cpp $(directives)

utest : CTvSet.o
	g++ -o utest.exe CTvSet.o $(boost_incs) $(main_incs) $(test_dir)/TvSetTest.cpp $(directives)

CTvSet.o:
	g++ -c $(main_dir)/CTvSet.cpp $(directives)

clean :
	rm -f *.o *.exe
