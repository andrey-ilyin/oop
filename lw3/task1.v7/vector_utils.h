#ifndef VECTOR_UTILS_
#define VECTOR_UTILS_

#include <cmath> //isgreaterequal and nan

struct Min3Vector
{
    double min1 = NAN;
    double min2 = NAN;
    double min3 = NAN;

    void operator() (double i);
};

struct VectorPlus
{
    double value = 0;

    double operator() (double i);
};

bool CompareNumbers(double i, double j);

#endif //VECTOR_UTILS_
