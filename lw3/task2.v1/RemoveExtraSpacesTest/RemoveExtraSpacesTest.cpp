#define BOOST_AUTO_TEST_MAIN

#include <boost/test/included/unit_test.hpp>
#include <string>
#include "RemoveExtraSpaces/RemoveExtraSpaces.h"

BOOST_AUTO_TEST_SUITE(RemoveExtraSpacesTest)

BOOST_AUTO_TEST_CASE(EmptyStringBeingProcessedIsEmptyString)
{
    std::string emptyString = RemoveExtraSpaces("");
    BOOST_CHECK(emptyString.empty());
}

BOOST_AUTO_TEST_CASE(StringWithoutSpacesBeingProcessedIsTheSame)
{
    std::string originalString = "TextWithoutSpaces";
    std::string processedString = RemoveExtraSpaces(originalString);
    BOOST_CHECK_EQUAL(originalString, processedString);
}

BOOST_AUTO_TEST_CASE(StringWithTrailingSpacesBeingProcessedIsTrimmed)
{
    std::string originalString = "Text with trailing spaces     ";
    std::string expectedString = "Text with trailing spaces";
    std::string processedString = RemoveExtraSpaces(originalString);
    BOOST_CHECK_EQUAL(processedString, expectedString);
}

BOOST_AUTO_TEST_CASE(StringWithBeginningSpacesBeingProcessedIsTrimmed)
{
    std::string originalString = "    Text with beginning spaces";
    std::string expectedString = "Text with beginning spaces";
    std::string processedString = RemoveExtraSpaces(originalString);
    BOOST_CHECK_EQUAL(processedString, expectedString);
}

BOOST_AUTO_TEST_CASE(TwoSpacesInTheMiddleAreRemoved)
{
    std::string originalString = "Text  with  two  spaces";
    std::string expectedString = "Text with two spaces";
    std::string processedString = RemoveExtraSpaces(originalString);
    BOOST_CHECK_EQUAL(processedString, expectedString);
}

BOOST_AUTO_TEST_CASE(RemoveAllExtraBlanks)
{
    std::string originalString = "  Text    with   extra   blanks   ";
    std::string expectedString = "Text with extra blanks";
    std::string processedString = RemoveExtraSpaces(originalString);
    BOOST_CHECK_EQUAL(processedString, expectedString);
}

BOOST_AUTO_TEST_SUITE_END()
