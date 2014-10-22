#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

void PrintUsage();
void PrintErrorMessage(int errorCode, int argumentIndex);

double StringToDouble(const char* str, bool &err);
char StringToMathSign(const char* str, bool &err);

double CalculateExpression(int argc, char* argv[], int &errorCode, int &errorArgumentIndex);
double Calculate(char operation, double firstArg, double secondArg);

const int MIN_PROGRAM_ARGUMENTS = 4;

enum ErrorCode
{
    ERR_NONE,
    ERR_INVALID_COUNT_OF_ARGUMENTS,
    ERR_INVALID_NUMBER_ARGUMENT,
    ERR_INVALID_SIGN_ARGUMENT
};

int main(int argc, char* argv[])
{
    int errorCode = ERR_NONE;
    int errorArgumentIndex = 0;
    double result = 0;

    if ( argc < MIN_PROGRAM_ARGUMENTS || argc % 2 != 0 )
    {   
        errorCode = ERR_INVALID_COUNT_OF_ARGUMENTS;
    }

    if ( errorCode == ERR_NONE )
    {
        result = CalculateExpression(argc, argv, errorCode, errorArgumentIndex);
    }

    if ( errorCode != ERR_NONE )
    {
        PrintErrorMessage(errorCode, errorArgumentIndex);
        PrintUsage();
    }
    else
    {
        printf("%.3f\n", result);
    }

    return 0;
}

double CalculateExpression(int argc, char* argv[], int &errorCode, int &errorArgumentIndex)
{
    double result = 0;
    bool err = false; 
    errorCode = ERR_NONE;

    double firstArg = (double)StringToDouble(argv[1], err);
    if ( err )
    {
        errorCode = ERR_INVALID_NUMBER_ARGUMENT;
        errorArgumentIndex = 1;
    }

    if ( !err )
    {
        for (int i = 2; i < (argc - 1); i = i + 2)
        {
            char sign = StringToMathSign(argv[i], err);
            if ( err )
            {
                errorCode = ERR_INVALID_SIGN_ARGUMENT;
                errorArgumentIndex = i;
                break;
            }
            double secondArg = StringToDouble(argv[i + 1], err);
            if ( err )
            {
                errorCode = ERR_INVALID_NUMBER_ARGUMENT;
                errorArgumentIndex = i;
                break;
            }
            firstArg = Calculate(sign, firstArg, secondArg);
        }
    }

    result = firstArg;
    return result;
}

void PrintUsage()
{    
    printf("Usage: eval.exe <number expression>\n");
    printf("\t<number expression> ::= <number> | \n");
    printf("\t<number expression> <sign> <number>\n");

    printf("Example: eval.exe 10 + 5\n");
    printf("eval.exe 4 \"*\" 3 - 2\n");
}

char StringToMathSign(const char* str, bool &err)
{
    char sign = ' ';
    err = false;
    
    if ( strlen( str ) != 1 )
    {
        err = true;
    }
    else
    {
        sign = str[0];
    }

    char signs[4] = {'+', '-', '*', '/'};
    std::set<char> availableSigns(signs, signs + 4);
    err = availableSigns.find(sign) == availableSigns.end();

    return sign;
}

double StringToDouble(const char* str, bool &err)
{
    char* pLastChar = NULL;
    double param = strtod(str, &pLastChar );
    err= ((*str == '\0') || (*pLastChar != '\0'));
    return param;
}

double Calculate(char operation, double firstArg, double secondArg)
{
    double result = 0;

    switch (operation)
    {
        case '+':
            result = firstArg + secondArg;
            break;
        case '-':
            result = firstArg - secondArg;
            break;
        case '*':
            result = firstArg * secondArg;
            break;
        case '/':
            result = firstArg / secondArg;
            break;
        default:
            break;
    }

    return result;
}

void PrintErrorMessage(int errorCode, int argumentIndex)
{
    switch ( errorCode )
    {
        case ERR_INVALID_COUNT_OF_ARGUMENTS:
            printf("Invalid count of program arguments.\n" );
            break;
        case ERR_INVALID_NUMBER_ARGUMENT:
            printf("Argument #%d is not a number.\n", argumentIndex);
            break;
        case ERR_INVALID_SIGN_ARGUMENT:
            printf("Argument #%d is not a valid math sign.\n", argumentIndex);
            break;
        default:
            break;
    }    
}
