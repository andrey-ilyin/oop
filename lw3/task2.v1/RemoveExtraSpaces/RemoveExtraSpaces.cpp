#include "RemoveExtraSpaces.h"

using namespace std;

std::string RemoveExtraSpaces(std::string const& arg)
{
    std::string result;

    size_t lastNotSpacePosition = arg.find_last_not_of(' ');
    if (lastNotSpacePosition != string::npos)
    {
        size_t firstNotSpacePosition = arg.find_first_not_of(' ');
        firstNotSpacePosition = (firstNotSpacePosition == string::npos) ? 0 : firstNotSpacePosition;

        result.reserve(lastNotSpacePosition - firstNotSpacePosition + 1);

        bool space = false;
        for (size_t position = firstNotSpacePosition; position <= lastNotSpacePosition; ++position)
        {
             if (arg[position] == ' ')
             {
                 space = true;
             }
             else
             {
                 if (space)
                 {
                     result.push_back(' ');
                 }
                 result.push_back(arg[position]);
                 space = false;
             }
        }
    }

    return result;
}
