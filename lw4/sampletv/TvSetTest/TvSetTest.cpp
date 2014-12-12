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

BOOST_AUTO_TEST_CASE(IsChannel0)
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


//---

struct TurnedOnTvSetFixture
{
    CTvSet tv;

    TurnedOnTvSetFixture()
    {
        tv.TurnOn();
    }
};

BOOST_FIXTURE_TEST_SUITE(TurnedOnTvSet, TurnedOnTvSetFixture)

BOOST_AUTO_TEST_CASE(BeingTurnedOffIsTurnedOffAtChannel0)
{
    BOOST_CHECK(tv.TurnOff());
    BOOST_CHECK(!tv.IsTurnedOn());
    BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
}

BOOST_AUTO_TEST_CASE(AllowSwitchingChannel)
{
    BOOST_CHECK(tv.SetChannel(42));
    BOOST_CHECK_EQUAL(tv.GetChannel(), 42);
}

BOOST_AUTO_TEST_CASE(BeingTurnedOffAndOnRestoresChannel)
{
    tv.SetChannel(42);
    tv.TurnOff();
    BOOST_CHECK(tv.TurnOn());
    BOOST_CHECK_EQUAL(tv.GetChannel(), 42);
}

BOOST_AUTO_TEST_SUITE_END()
