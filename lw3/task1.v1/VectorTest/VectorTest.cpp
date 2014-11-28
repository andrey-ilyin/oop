#define BOOST_AUTO_TEST_MAIN

#include <boost/test/included/unit_test.hpp>
#include <string>

BOOST_AUTO_TEST_CASE(TestThatComputerWorksCorrectly)
{
	int x = 2;
	int y = 2;
	BOOST_CHECK_EQUAL(x + y, 4);

	std::string hello("Hello, Unit Test!");
	BOOST_CHECK(!hello.empty());
}
