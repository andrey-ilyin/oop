#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));


    ostream_iterator<double> output(cout, " ");
    copy_if(numbers.begin(), numbers.end(), output, [] (double item){ return (item > 0); });

    return 0;
}
