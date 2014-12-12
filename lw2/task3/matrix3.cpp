#include "matrix3.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>

void MultMatrix3(const Matrix3& m1, const Matrix3& m2, Matrix3& result)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            result[i][j] = m1[i][0]*m2[0][j] + m1[i][1]*m2[1][j] + m1[i][2]*m2[2][j];
        }
    }
}

void PrintMatrix3(const Matrix3& m)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << setprecision(3) << fixed << m[i][j];
            if ( j != 2 )
            {
                cout << "\t";
            }
        }
        cout << endl;
    }
}

Matrix3ReadError ReadMatrix3(const string& fileName, Matrix3& result)
{
    Matrix3ReadError errCode = ERR_NONE;
    FILE* file = fopen(fileName.c_str(), "r");
    double number = 0;
    if ( file )
    {
        for (int i = 0; (i < 3) && (errCode == ERR_NONE); ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if ( !feof(file))
                {
                    //TODO: check if specified element is valid float
                    fscanf(file, "%lf", &number);
                    result[i][j] = number;
                }
                else
                {
                    errCode = ERR_INVALID_MATRIX;
                    break;
                }
            }
        }
        fclose(file);
    }
    else
    {
        errCode = ERR_UNABLE_TO_OPEN_FILE;
    }

    return errCode;
}
