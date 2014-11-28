#define BOOST_AUTO_TEST_MAIN

#include <boost/test/included/unit_test.hpp>
#include <string>
#include <vector>
#include "Vector/VectorProcessor.h"

BOOST_AUTO_TEST_CASE(TestThatComputerWorksCorrectly)
{
    int x = 2;
    int y = 2;
    BOOST_CHECK_EQUAL(x + y, 4);

    std::string hello("Hello, Unit Test!");
    BOOST_CHECK(!hello.empty());

    BOOST_CHECK_NE(4, 5);
}

BOOST_AUTO_TEST_SUITE(VectorProcessingTests)

BOOST_AUTO_TEST_CASE(EmptyVector)
{
    std::vector<double> empty;
    ProcessVector(empty);
	BOOST_CHECK(empty.empty());
}

BOOST_AUTO_TEST_CASE(VectorContainingSinglePositiveItem)
{
	std::vector<double> singleItemVector = { 42 };
	ProcessVector(singleItemVector);
	BOOST_CHECK_EQUAL(singleItemVector.size(), 1u);
	BOOST_CHECK_EQUAL(singleItemVector.front(), 84.0);
}

BOOST_AUTO_TEST_CASE(VectorContainingSingleNegativeItem)
{
	std::vector<double> singleItemVector = { -42 };
	ProcessVector(singleItemVector);
	BOOST_CHECK_EQUAL(singleItemVector.size(), 1u);
	BOOST_CHECK_EQUAL(singleItemVector.front(), -42.0);
}

BOOST_AUTO_TEST_CASE(VectorContainingTwoPositiveItems)
{
	std::vector<double> twoItems = {2, 4};
	ProcessVector(twoItems);
	BOOST_CHECK_EQUAL(twoItems.size(), 2u);
	std::vector<double> const expectedItems = {5, 7};
	BOOST_CHECK(twoItems == expectedItems);
}

BOOST_AUTO_TEST_SUITE_END()
