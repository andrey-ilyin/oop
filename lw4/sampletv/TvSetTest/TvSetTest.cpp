#define BOOST_AUTO_TEST_MAIN

#include <boost/test/included/unit_test.hpp>
#include <string>
#include "TvSet/CTvSet.h"

struct JustCreatedTvSetFixture
{
    CTvSet tv;
};

BOOST_FIXTURE_TEST_SUITE(JustCreatedTvSet, JustCreatedTvSetFixture)

BOOST_AUTO_TEST_CASE(IsTurnedOff)
{
    BOOST_CHECK(!tv.IsTurnedOn());
}

BOOST_AUTO_TEST_CASE(IsChannelZero)
{
    BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
}

BOOST_AUTO_TEST_CASE(BeingTurnedOnIsTurnedOnAtChannel1)
{
    BOOST_CHECK(tv.TurnOn());
    BOOST_CHECK(tv.IsTurnedOn());
    BOOST_CHECK_EQUAL(tv.GetChannel(), 1);
}

BOOST_AUTO_TEST_SUITE_END()
