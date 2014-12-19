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

BOOST_AUTO_TEST_CASE(SetWithOneElement)
{
	std::set<std::size_t> primes = GeneratePrimeNumbersSet(2);
	BOOST_CHECK(primes.find(2) != primes.end());
}

BOOST_AUTO_TEST_CASE(PrimesTo10)
{
	std::size_t expectedPrimesArray[] = 
	{
		2, 3, 5, 7
	};
	const size_t NUMBERS_COUNT = sizeof(expectedPrimesArray) / sizeof(*expectedPrimesArray);
	std::set<std::size_t> expectedPrimes;
	expectedPrimes.insert(&expectedPrimesArray[0], &expectedPrimesArray[NUMBERS_COUNT]);

	std::set<std::size_t> primes = GeneratePrimeNumbersSet(10);
	BOOST_CHECK(expectedPrimes == primes);
}


BOOST_AUTO_TEST_SUITE_END()
