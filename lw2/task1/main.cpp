#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void PrintUsage();
void FindText(ifstream& haystack, string& needle, vector<size_t>& foundLines);

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Invalid arguments count." << endl;
        PrintUsage();
        return 1;
    }

    string fileName(argv[1]);
    string searchString(argv[2]);

    ifstream filein(fileName);
    if ( !filein.good())
    {
        cout << "Unable to open file '" << fileName << "'." << endl;
        return 1;
    }

    if (searchString.empty())
    {
        cout << "Search string is empty." << endl;
        return 1;
    }

    vector<size_t> foundLines;
    FindText(filein, searchString, foundLines);

    if (foundLines.empty())
    {
        cout << "Text not found." << endl;
        return 1;
    }

    for (size_t i = 0; i < foundLines.size(); ++i)
    {
        cout << foundLines[i] << endl;
    }

    return 0;
}

void PrintUsage()
{
    cout << "Usage:" << endl <<
            "\t" << "findtext <text file> <search text>" << endl;
}

void FindText(ifstream& haystack, string& needle, vector<size_t>& foundLines)
{
    size_t counter = 0;
    while (!haystack.eof())
    {
        string str;
        getline(haystack, str);
        if (str.find(needle) != string::npos)
        {
            foundLines.push_back(counter);
        }
        ++counter;
    }
}
