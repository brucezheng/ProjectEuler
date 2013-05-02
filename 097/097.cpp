/*
	Bruce Zheng
	Problem 097
	4/18/2013

	We only want to keep track of the last ten digits of our gigantic number, to avoid overflow.
*/

#include <iostream>
#include <ctime>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

int main()
{
	time_t start = clock();
	long long digits = 1;
	for (int i = 0; i < 7830457; ++i) {
		digits *= 2;
		digits %= 10000000000;
	}
	digits *= 28433;
	digits %= 10000000000;
	digits += 1;
	time_t end = clock();
	cout << digits << endl;
	double dur = double(end-start)/double(CLOCKS_PER_SEC);
	cout << "TIME:" << dur << endl;
	pause();
}