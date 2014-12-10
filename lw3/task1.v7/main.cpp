#include <iostream>
#include <vector>
#include <algorithm> //for_each
#include <assert.h>
#include <iterator>

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

    vector<double> mins3(3);
    partial_sort_copy(numbers.begin(), numbers.end(), mins3.begin(), mins3.end());
    double sumOfMins = mins3[0] + mins3[1] + mins3[2];

    transform(numbers.begin(), numbers.end(), numbers.begin(), bind2nd(plus<double>(), sumOfMins));

    sort(numbers.begin(), numbers.end());

    copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, " "));
    cout << endl;

    return 0;
}
