#include "RemoveExtraSpaces.h"

using namespace std;

std::string RemoveExtraSpaces(std::string const& arg)
{
    std::string result = "";

    size_t lastNotSpacePosition = arg.find_last_not_of(' ');
    if (lastNotSpacePosition != string::npos)
    {
        size_t firstNotSpacePosition = arg.find_first_not_of(' ');
        firstNotSpacePosition = (firstNotSpacePosition == string::npos) ? 0 : firstNotSpacePosition;

        result = arg.substr(firstNotSpacePosition, lastNotSpacePosition + 1);
    }

    return result;
}
