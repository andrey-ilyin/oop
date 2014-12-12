#include <iostream>
#include "matrix3.h"

using namespace std;

void PrintReadMatrixError(const int errCode, const char* fileName);
void PrintUsage();

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Invalid paramaters number." << endl;
        PrintUsage();
        return 1;
    }

    Matrix3 m1, m2, result;

    int errCode = ReadMatrix3(argv[1], m1);
    if ( errCode != ERR_NONE )
    {
        PrintReadMatrixError(errCode, argv[1]);
        return 1;
    }
    errCode = ReadMatrix3(argv[2], m2);
    if ( errCode != ERR_NONE )
    {
        PrintReadMatrixError(errCode, argv[2]);
        return 1;
    }

    MultMatrix3(m1, m2, result);
    PrintMatrix3(result);

    return 0;
}

void PrintReadMatrixError(const int errCode, const char* fileName)
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

void PrintUsage()
{
    cout << "Usage:" << endl <<
            "multmatrix <matrix file1> <matrix file2>" << endl;
}
