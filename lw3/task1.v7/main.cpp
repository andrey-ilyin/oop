#include <iostream>
#include <vector>
#include <cmath> //isgreaterequal
#include <algorithm> //for_each
#include <assert.h>

using namespace std;

struct Min3Vector
{
    double min1 = NAN;
    double min2 = NAN;
    double min3 = NAN;

    void operator() (double i)
    {
        if (std::isnan(min1) || isgreaterequal(min1, i))
        {
            min3 = min2;
            min2 = min1;
            min1 = i;
        }
        else if(std::isnan(min2) || isgreaterequal(min2, i))
        {
            min3 = min2;
            min2 = i;
        }
        else if(std::isnan(min3) || isgreaterequal(min3, i))
        {
            min3 = i;
        }
    }
};

struct VectorPlus
{
    double value = 0;

    double operator() (double i)
    {
        return i + value;
    }
};

bool CompareNumbers(double i, double j)
{
    return !isgreaterequal(i, j);
}

int main(int argc, char* argv[])
{
    vector<int> numbers;
    double number;

    while (cin >> number)
    {
        numbers.push_back(number);
    }

    assert(numbers.size() > 2);

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
