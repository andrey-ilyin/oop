directives = -std=gnu++11
#boost_libs = -L"C:/sdk/boost_1_57_0/libs"
boost_incs = -I"C:/sdk/boost_1_57_0"
main_incs = -I"."
main_dir = RemoveExtraSpaces
test_dir = RemoveExtraSpacesTest

remove : RemoveExtraSpaces.o
	g++ -o remove.exe RemoveExtraSpaces.o $(boost_incs) $(main_dir)/main.cpp $(directives)

RemoveExtraSpaces.o :
	g++ -c $(main_dir)/RemoveExtraSpaces.cpp $(directives)

utest : RemoveExtraSpaces.o
	g++ -o utest.exe RemoveExtraSpaces.o $(boost_incs) $(main_incs) $(test_dir)/RemoveExtraSpacesTest.cpp $(directives)

clean :
	rm -f *.o *.exe
