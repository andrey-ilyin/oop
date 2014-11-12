#include <iostream>
#include "matrix3.h"

using namespace std;

void printReadMatrixError(const int errCode, const char* fileName);
void printUsage();

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Invalid paramaters number." << endl;
        printUsage();
        return 1;
    }

    Matrix3 m1, m2, result;

    int errCode = ERR_NONE;
    readMatrix3(argv[1], m1, errCode);
    if ( errCode != ERR_NONE )
    {
        printReadMatrixError(errCode, argv[1]);
        return 1;
    }
    readMatrix3(argv[2], m2, errCode);
    if ( errCode != ERR_NONE )
    {
        printReadMatrixError(errCode, argv[2]);
        return 1;
    }

    multMatrix3(m1, m2, result);
    printMatrix3(result);

    return 0;
}

void printReadMatrixError(const int errCode, const char* fileName)
{
    switch (errCode)
    {
        case ERR_UNABLE_TO_OPEN_FILE:
            cout << "Unable to open file '" << fileName << "'" << endl;
            break;
        case ERR_INVALID_MATRIX:
            cout << "Invalid matrix format in file '" << fileName << "'. Specified matrix is not 3x3" << endl;
            break;
        default:
            break;
    }
}

void printUsage()
{
    cout << "Usage:" << endl <<
            "multmatrix <matrix file1> <matrix file2>" << endl;
}