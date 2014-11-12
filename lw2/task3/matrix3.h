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

void multMatrix3(const Matrix3&, const Matrix3&, Matrix3&);

void printMatrix3(const Matrix3&);
void readMatrix3(const string&, Matrix3&, int&);

#endif //MATRIX3_H
