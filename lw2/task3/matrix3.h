#ifndef MATRIX3_H
#define MATRIX3_H

#include <string>

using namespace std;

typedef double Matrix3[3][3];

enum Matrix3ReadError
{
    ERR_NONE,
    ERR_UNABLE_TO_OPEN_FILE,
    ERR_INVALID_MATRIX
};

void MultMatrix3(const Matrix3& m1, const Matrix3& m2, Matrix3& result);

void PrintMatrix3(const Matrix3& m);
Matrix3ReadError ReadMatrix3(const string& fileName, Matrix3& result);

#endif //MATRIX3_H
