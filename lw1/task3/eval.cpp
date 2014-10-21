#include <stdio.h>
#include <stdlib.h>

void PrintUsage();
int StringToInt(const char* str, bool &err);
int StringToDouble(const char* str, bool &err);
double Calculate(char operation, double firstArg, double secondArg);

int main(int argc, char* argv[])
{
	if ( argc < 4 || argc % 2 != 0 )
	{	
		PrintUsage();
		return 1;
	}

	bool err = false;
	double firstArg = (double)StringToDouble(argv[1], err);
	for (int i = 2; i < (argc - 1); i = i + 2)
	{
		char sign = argv[i][0];
		double secondArg = (double)StringToDouble(argv[i+1], err);
		firstArg = Calculate(sign, firstArg, secondArg);
	}

	printf("%.3f\n", firstArg);

	return 0;
}

void PrintUsage()
{
	printf("Usage: eval.exe <number expression>\n");
	printf("<number expression> ::= <number> | \n");
	printf("<number expression> <sign> <number>\n");
	printf("Example: eval.exe 10 + 5\n");
	printf("eval.exe 4 '*' 3 - 2\n");
}

int StringToInt(const char* str, bool &err)
{
	char* pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err= ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int StringToDouble(const char* str, bool &err)
{
	double param = 0;
	param = strtod(str, NULL);
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