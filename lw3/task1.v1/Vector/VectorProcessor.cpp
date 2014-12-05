#include "VectorProcessor.h"                                                                                 

#include <cstdlib>
#include <algorithm> //std::transform


void ProcessVector(std::vector<double> & numbers)
{
    size_t positivesCount = 0;
    double positivesSum = 0;
    for (auto number : numbers)
    {
        if (number > 0)
        {
            ++positivesCount;
            positivesSum += number;
        }
    }
    const double positivesAvg = (positivesCount > 0) ? positivesSum / positivesCount : 0;

    std::transform(numbers.begin(), numbers.end(), numbers.begin(), 
        [positivesAvg](double item){
            return item + positivesAvg;
    });
}
