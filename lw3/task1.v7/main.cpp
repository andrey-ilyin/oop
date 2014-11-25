#include <iostream>
#include <vector>
#include <algorithm> //for_each
#include <assert.h>
#include "vector_utils.h"

using namespace std;

int main(int argc, char* argv[])
{
    vector<double> numbers;
    double number;

    while (cin >> number)
    {
        numbers.push_back(number);
    }

    if (numbers.size() < 3)
    {
        cout << "You should enter at least three numbers." << endl;
        return 1;
    }

    assert(numbers.size() >= 3);

    Min3Vector mins;
    mins = for_each(numbers.begin(), numbers.end(), mins);

    VectorPlus plus;
    plus.value = (mins.min1 + mins.min2 + mins.min3);

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
