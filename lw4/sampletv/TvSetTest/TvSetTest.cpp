#define BOOST_AUTO_TEST_MAIN

#include <boost/test/included/unit_test.hpp>
#include <string>
#include "TvSet/CTvSet.h"

BOOST_AUTO_TEST_SUITE(JustCreatedTvSet)

BOOST_AUTO_TEST_CASE(IsTurnedOff)
{
    CTvSet tv;
    BOOST_CHECK(!tv.IsTurnedOn());
}

BOOST_AUTO_TEST_CASE(IsChannelZero)
{
    CTvSet tv;
    BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
}

BOOST_AUTO_TEST_SUITE_END()
