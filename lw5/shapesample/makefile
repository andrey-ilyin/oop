directives = -std=gnu++11
#boost_libs = -L"C:/sdk/boost_1_57_0/libs"
boost_incs = -I"C:/sdk/boost_1_57_0"
main_incs = -I"."
main_dir = Shapes
test_dir = ShapesTest

main : Point.o
	g++ -o shapes.exe Point.o $(boost_incs) $(main_dir)/main.cpp $(main_incs) $(directives)

utest : Point.o
	g++ -o utest.exe Point.o $(boost_incs) $(main_incs) $(test_dir)/PointTest.cpp $(directives)

Point.o:
	g++ -c $(main_dir)/Point.cpp $(main_incs) $(directives)

clean :
	rm -f *.o *.exe
