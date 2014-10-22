#include <stdio.h>
#include <stdlib.h>

const int DEFAULT_MIN_NUMBER = 1;
const int DEFAULT_MAX_NUMBER = 1000;

int SumDigits(int i);
int StringToInt(const char* str, bool &err);

void PrintNumbers(int maxNumber);
void PrintUsage();

int main(int argc, char* argv[])
{
    int maxNumber = DEFAULT_MAX_NUMBER;

    if ( argc > 1 )
    {
        bool err = false;
        maxNumber = StringToInt(argv[1], err);
        if ( err )
        {
            printf("Argument is not a valid number.\n");
            PrintUsage();
            return 1;
        }
    }
    if ( maxNumber < 1 )
    {
        printf("Please specify number greater than 1.\n");
        PrintUsage();
        return 1;
    }

    PrintNumbers(maxNumber);

    return 0;
}

void PrintNumbers(int maxNumber)
{
    for (int i = DEFAULT_MIN_NUMBER; i <= maxNumber; ++i)
    {
        if ( i % SumDigits( i ) == 0 )
        {
            if ( i > DEFAULT_MIN_NUMBER )
            {
                printf(", ");
            }
            printf("%d", i);
        }
    }
    printf("\n");
}

int SumDigits(int i)
{
    int sum = 0;

    while (i != 0)
    {
        sum += i % 10;
        i /= 10;
    }

    return sum;
}

int StringToInt(const char* str, bool &err)
{
    char * pLastChar = NULL;
    int param = strtol(str, &pLastChar, 10);
    err = ((*str == '\0') || (*pLastChar != '\0'));
    return param;    
}

void PrintUsage()
{
    printf("Usage: \n");
    printf("\tdivision_by_sum_of_digits.exe\n");
    printf("\tdivision_by_sum_of_digits.exe <number>\n");
}
