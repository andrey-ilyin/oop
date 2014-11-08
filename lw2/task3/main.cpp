#include <iostream>
#include "matrix3.h"

using namespace std;

int main()
{
    Matrix3 m1 = {{5, 8, -4},
            {6, 9, -5},
            {4, 7, -3}};
    Matrix3 m2 = {{3, 2, 5},
            {4, -1, 3},
            {9, 6, 5}};
    Matrix3 result;

    multMatrix3(m1, m2, result);
    printMatrix3(result);

    return 0;
}
