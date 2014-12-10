#include <iostream>
#include <vector>
#include <algorithm> //for_each
#include <assert.h>
#include <iterator>
#include "vector_utils.h"

using namespace std;

int main(int argc, char* argv[])
{
    vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));

    if (numbers.size() < 3)
    {
        cout << "You should enter at least three numbers." << endl;
        return 1;
    }

    assert(numbers.size() >= 3);

    vector<double> mins3 (3);
    partial_sort_copy(numbers.begin(), numbers.end(), mins3.begin(), mins3.end());
    double sumOfMins = mins3[0] + mins3[1] + mins3[2];
    
    VectorPlus plus;
    plus.value = sumOfMins;

    transform(numbers.begin(), numbers.end(), numbers.begin(), plus);

    sort(numbers.begin(), numbers.end(), CompareNumbers);

    for(auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        if (it != numbers.begin())
            cout << " ";
        cout << *it;
    }
    cout << endl;

    return 0;
}
