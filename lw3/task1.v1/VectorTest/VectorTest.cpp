#define BOOST_AUTO_TEST_MAIN

#include <boost/test/included/unit_test.hpp>
#include <string>
#include <vector>
#include "Vector/VectorProcessor.h"

bool VerifyVectorProcessing(std::vector<double> inputNumbers, std::vector<double> const& expectedNumbers)
{
    ProcessVector(inputNumbers);
    return (inputNumbers == expectedNumbers);
}

BOOST_AUTO_TEST_SUITE(VectorProcessingTests)

BOOST_AUTO_TEST_CASE(AllTestCases)
{
    BOOST_CHECK(VerifyVectorProcessing({}, {}));
    BOOST_CHECK(VerifyVectorProcessing({42}, {84.0}));
    BOOST_CHECK(VerifyVectorProcessing({-42}, {-42.0}));
    BOOST_CHECK(VerifyVectorProcessing({2,4}, {5,7}));
    BOOST_CHECK(VerifyVectorProcessing({0}, {0}));
    BOOST_CHECK(VerifyVectorProcessing({42, -42},{84, 0}));
    BOOST_CHECK(VerifyVectorProcessing({1, 2},{2.5, 3.5}));
}

BOOST_AUTO_TEST_SUITE_END()
