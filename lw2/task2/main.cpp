#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int StringToInt(const char* str, bool &err);
int FlipByte(int number);

void PrintUsage();

int main(int argc, char* argv[])
{
    //cout << "Hello, World!" << endl;

    if ( argc != 2 )
    {
        cout << "Invalid number of arguments." << endl;
        PrintUsage();
        return 1;
    }

    bool err = false;
    int number = StringToInt(argv[1], err);

    if ( err )
    {
        cout << "Argument is not a valid number." << endl;
        PrintUsage();
        return 1;
    }

    if ( number < 0 || number > 255 )
    {
        cout << "Specified number exceed the limits [0, 255]." << endl;
        return 1;
    }

    number = FlipByte(number);
    cout << number;

    return 0;
}

int StringToInt(const char* str, bool &err)
{
    char * pLastChar = NULL;
    int param = strtol(str, &pLastChar, 10);
    err = ((*str == '\0') || (*pLastChar != '\0'));
    return param;
}

int FlipByte(int number)
{
    int result = 0;

    result = ( ( number & 128 ) >> 7 ) |
            ( ( number & 64 ) >> 5 )   |
            ( ( number & 32 ) >> 3)    |
            ( ( number & 16 ) >> 1 )   |
            ( ( number & 8 )  << 1 )   |
            ( ( number & 4 )  << 3 )   |
            ( ( number & 2 )  << 5 )   |
            ( ( number & 1 )  << 7 );

    return result;
}

void PrintUsage()
{
    cout << "flipbyte.exe <number>" << endl;
}
