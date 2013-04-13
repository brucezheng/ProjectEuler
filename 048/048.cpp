/*
	Bruce Zheng
	Problem 048
	4/13/2013

	We're only concerned with the last 10 digits, so the function selfpower only keeps the last 10
	digits after every multiplication. In addition, if the result ever turns out to be zero, we
	know that the last 10 digits must end up being zero, so we break the loop and return zero. This
	would save a bit of runtime.
*/

#include <iostream>
#include <ctime>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

long long selfpower(int n)
{
	long long result = 1;
	for (int i = 0; i < n; ++i) {
		result *= long long(n);
		result %= 10000000000;
		if (result == 0) return 0;
	}
	return result;
}

int main()
{
	time_t start = clock();
	long long sum = 0;
	for (int i = 1; i < 1001; ++i) {
		sum += selfpower(i);
	}
	sum %= 10000000000;
	time_t end = clock();
	double dur = double(end - start)/double(CLOCKS_PER_SEC);
	cout << sum << endl << "TIME: " << dur;
	pause();
}