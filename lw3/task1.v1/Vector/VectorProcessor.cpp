#include "VectorProcessor.h"

#include <cstdlib>
#include <algorithm> //std::transform
#include <functional> //std::plus

void ProcessVector(std::vector<double> & numbers)
{
	if (numbers.size() == 1)
	{
		if (numbers[0] > 0)
		{
			numbers[0] += numbers[0];
		}
	}
	else
	{
		double avg = 0;
		for (size_t i = 0; i < numbers.size(); ++i)
		{
			avg += numbers[i];
		}
		avg /= numbers.size();
		std::transform(numbers.begin(), numbers.end(), numbers.begin(), bind2nd(std::plus<double>(), avg));
	}
}
