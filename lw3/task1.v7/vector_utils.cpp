#include "vector_utils.h"

bool CompareNumbers(double i, double j)
{
    return !std::isgreaterequal(i, j);
}

void Min3Vector::operator() (double i)
{
    if (std::isnan(min1) || std::isgreaterequal(min1, i))
    {
        min3 = min2;
        min2 = min1;
        min1 = i;
    }
    else if(std::isnan(min2) || std::isgreaterequal(min2, i))
    {
        min3 = min2;
        min2 = i;
    }
    else if(std::isnan(min3) || std::isgreaterequal(min3, i))
    {
        min3 = i;
    }
}

double VectorPlus::operator() (double i)
{
    return i + value;
}
