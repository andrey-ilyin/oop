#include <iostream>
#include <set>
#include <iterator>
#include "PrimeNumbers.h"

using namespace std;

int main(int argc, char* argv[])
{
	size_t upperBound;
	if (cin >> upperBound)
	{
		std::set<std::size_t> primes = GeneratePrimeNumbersSet(upperBound);

		cout << "Primes: " << endl;
		copy(primes.begin(), primes.end(), ostream_iterator<size_t>(cout, ", "));
		cout << endl;
	}
    

	return 0;
}
