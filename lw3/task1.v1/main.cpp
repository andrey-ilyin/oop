#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	vector<double> numbers;
	istream_iterator<double> start(cin);
	istream_iterator<double> end;
	auto where = back_inserter(numbers);
	copy(start, end, where);

    return 0;
}
