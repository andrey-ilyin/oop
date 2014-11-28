#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include "VectorProcessor.h"

using namespace std;

int main(int argc, char* argv[])
{
    vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
    ostream_iterator<double> output(cout, " ");
    auto IsGreaterThan0 = bind2nd(greater<double>(), 0);   
    copy_if(numbers.begin(), numbers.end(), output, IsGreaterThan0);

    return 0;
}
