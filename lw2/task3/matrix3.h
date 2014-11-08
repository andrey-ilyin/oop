#ifndef MATRIX3_H
#define MATRIX3_H

#include <string>

using namespace std;


typedef int Matrix3[3][3];

void multMatrix3(const Matrix3&, const Matrix3&, Matrix3&);
void zeroMatrix3(Matrix3&);

void printMatrix3(const Matrix3&);
void readMatrix3(const string&, Matrix3&);

#endif //MATRIX3_H
