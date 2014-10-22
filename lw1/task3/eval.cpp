#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

void PrintUsage();
void PrintInvalidNumberArgument(int elementIndex);
double StringToDouble(const char* str, bool &err);
double Calculate(char operation, double firstArg, double secondArg);
char StringToMathSign(const char* str, bool &err);

const int MIN_PROGRAM_ARGUMENTS = 4;

int main(int argc, char* argv[])
{
    if ( argc < MIN_PROGRAM_ARGUMENTS || argc % 2 != 0 )
    {   
        printf("Invalid count of program arguments.\n" );
        PrintUsage();
        return 1;
    }

    bool err = false;
    double firstArg = (double)StringToDouble(argv[1], err);
    if ( err )
    {
        PrintInvalidNumberArgument(1);
        PrintUsage();
        return 1;
    }

    for (int i = 2; i < (argc - 1); i = i + 2)
    {
        char sign = StringToMathSign(argv[i], err);
        if ( err )
        {
            printf("Argument #%d is not a valid math sign.\n", i);
            PrintUsage();
            return 1;
        }
        double secondArg = (double)StringToDouble(argv[i+1], err);
        if ( err )
        {
            PrintInvalidNumberArgument(i+1);
            PrintUsage();
            return 1;
        }
        firstArg = Calculate(sign, firstArg, secondArg);
    }

    printf("%.3f\n", firstArg);

    return 0;
}

void PrintUsage()
{    
    printf("Usage: eval.exe <number expression>\n");
    printf("\t<number expression> ::= <number> | \n");
    printf("\t<number expression> <sign> <number>\n");

    printf("Example: eval.exe 10 + 5\n");
    printf("eval.exe 4 '*' 3 - 2\n");
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

void PrintInvalidNumberArgument(int elementIndex)
{
    printf("Argument #%d is not a number.\n", elementIndex);
}
