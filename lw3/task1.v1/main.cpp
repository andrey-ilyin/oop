#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	istream_iterator<double> start(cin);
	istream_iterator<double> end;
	vector<double> numbers(start, end);

    return 0;
}
