#include "PrimeNumbers.h"

std::set<std::size_t> GeneratePrimeNumbersSet(std::size_t upperBound)
{
	std::set<std::size_t> primes;

	if (upperBound >= 2)
	{
		for (std::size_t number = 2; number <= upperBound; ++number)
		{
			primes.insert(number);
		}

		for (std::set<std::size_t>::iterator it = primes.begin(); it != primes.end(); ++it)
		{
			std::size_t prime = *it;

			std::size_t number = 2*prime;
			while (number <= upperBound)
			{
				if (number % prime == 0)
				{
					primes.erase(number);
				}
				number += prime;
			}
		}
	}

	return primes;
}
