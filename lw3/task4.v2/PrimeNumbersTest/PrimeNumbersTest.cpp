#define BOOST_AUTO_TEST_MAIN

#include <boost/test/included/unit_test.hpp>
#include <set>
#include "PrimeNumbers/PrimeNumbers.h"

BOOST_AUTO_TEST_SUITE(PrimeNumbersTests)

BOOST_AUTO_TEST_CASE(EmptySetFor0)
{
	std::set<std::size_t> primes = GeneratePrimeNumbersSet(0);
	BOOST_CHECK(primes.empty());
}

BOOST_AUTO_TEST_CASE(EmptySetForNegativeUpperBound)
{
	std::set<std::size_t> primes = GeneratePrimeNumbersSet(-1);
	BOOST_CHECK(primes.empty());
}

BOOST_AUTO_TEST_CASE(SetWithOneElement)
{
/*	std::set<std::size_t> primes = GeneratePrimeNumbersSet(2);
	BOOST_CHECK(primes.find(2) != primes.end());*/
}

BOOST_AUTO_TEST_SUITE_END()
