#include "matrix3.h"
#include <iostream>

void multMatrix3(const Matrix3& m1, const Matrix3& m2, Matrix3& result)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            result[i][j] = m1[i][0]*m2[0][j] + m1[i][1]*m2[1][j] + m1[i][2]*m2[2][j];
        }
    }
}

void zeroMatrix3(Matrix3& m)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            m[i][j] = 0;
        }
    }
}

void printMatrix3(const Matrix3& m)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << m[i][j] << '\t';
        }
        cout << endl;
    }
}

void readMatrix3(const string& fileName, Matrix3& result)
{

}
