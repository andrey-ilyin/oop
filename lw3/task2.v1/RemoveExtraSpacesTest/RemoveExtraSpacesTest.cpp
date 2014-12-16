#define BOOST_AUTO_TEST_MAIN

#include <boost/test/included/unit_test.hpp>
#include <string>
#include "RemoveExtraSpaces/RemoveExtraSpaces.h"

bool VerifyRemoveExtraSpaces(std::string const& inputString, std::string const& expectedString)
{
    std::string processedString = RemoveExtraSpaces(inputString);
    return (processedString == expectedString);
}

BOOST_AUTO_TEST_SUITE(RemoveExtraSpacesTests)

BOOST_AUTO_TEST_CASE(AllTestCases)
{
    BOOST_CHECK(VerifyRemoveExtraSpaces("", ""));
    BOOST_CHECK(VerifyRemoveExtraSpaces("TextWithoutSpaces", "TextWithoutSpaces"));
    BOOST_CHECK(VerifyRemoveExtraSpaces("Normal text with some spaces", "Normal text with some spaces"));
    BOOST_CHECK(VerifyRemoveExtraSpaces("Text with trailing spaces     ", "Text with trailing spaces"));
    BOOST_CHECK(VerifyRemoveExtraSpaces("    Text with beginning spaces", "Text with beginning spaces"));
    BOOST_CHECK(VerifyRemoveExtraSpaces("Text  with  two  spaces", "Text with two spaces"));
    BOOST_CHECK(VerifyRemoveExtraSpaces("  Text    with   extra   blanks   ", "Text with extra blanks"));
}

BOOST_AUTO_TEST_SUITE_END()
