#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
    copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, " "));

    return 0;
}
