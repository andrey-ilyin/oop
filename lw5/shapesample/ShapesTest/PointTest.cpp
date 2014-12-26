#define BOOST_AUTO_TEST_MAIN

#include <boost/test/included/unit_test.hpp>
#include <string>
#include "Shapes/Point.h"

struct PointFixture
{
	const CPoint pt = CPoint(13.2, 30.7);
	const IShape & ptAsShape = pt;
};

BOOST_FIXTURE_TEST_SUITE(Point, PointFixture);

BOOST_AUTO_TEST_CASE(HasCoords)
{
	BOOST_CHECK_EQUAL(pt.GetX(), 13.2);
	BOOST_CHECK_EQUAL(pt.GetY(), 30.7);
}

BOOST_AUTO_TEST_CASE(IsAtOriginByDefault)
{
	const CPoint pt;
	BOOST_CHECK_EQUAL(pt.GetX(), 0);
	BOOST_CHECK_EQUAL(pt.GetY(), 0);
}

BOOST_AUTO_TEST_CASE(HasZeroArea)
{
	BOOST_CHECK_EQUAL(ptAsShape.GetArea(), 0);
}

BOOST_AUTO_TEST_CASE(HasZeroPerimiter)
{
	BOOST_CHECK_EQUAL(ptAsShape.GetPerimiter(), 0);
}

BOOST_AUTO_TEST_CASE(HasStringRepresentation)
{
	BOOST_CHECK_EQUAL(ptAsShape.ToString(), "point 13.2 30.7");
}

BOOST_AUTO_TEST_SUITE_END();
