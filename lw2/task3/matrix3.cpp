#include "matrix3.h"
#include <iostream>
#include <stdio.h>

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

void printMatrix3(const Matrix3& m)
{
    cout.precision(3);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            //TODO: think how to make this using cout
            printf("%.3f", m[i][j]);
            if ( j != 2 )
            {
                cout << "\t";
            }
        }
        cout << endl;
    }
}

void readMatrix3(const string& fileName, Matrix3& result, int& errCode)
{
    errCode = ERR_NONE;
    FILE* fo = fopen(fileName.c_str(), "r");
    double el = 0;
    if ( fo )
    {
        for (int i = 0; (i < 3) && (errCode == ERR_NONE); ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if ( !feof(fo))
                {
                    //TODO: check if specified element is valid float
                    fscanf(fo, "%lf", &el);
                    result[i][j] = el;
                }
                else
                {
                    errCode = ERR_INVALID_MATRIX;
                    break;
                }
            }
        }
        fclose(fo);
    }
    else
    {
        errCode = ERR_UNABLE_TO_OPEN_FILE;
    }
}
