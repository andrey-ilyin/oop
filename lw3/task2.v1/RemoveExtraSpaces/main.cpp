#include <iostream>
#include <string>
#include "RemoveExtraSpaces.h"

int main(int argc, char* argv[])
{
	std::string text;
	std::getline(std::cin, text);

	std::cout << "#" << text << "#" << std::endl;
	std::cout << "#" << RemoveExtraSpaces(text) << "#" << std::endl;

    return 0;
}
