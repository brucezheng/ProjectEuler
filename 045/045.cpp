/*
	Bruce Zheng
	Problem 045
	4/12/2013

	Just borrowed code from previous questions with pentagonal/triangular numbers. Check each
	hexagonal number to see if it is pentagonal/triangular.
*/

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

bool istrig(long long n)
{
	long long k = long long(sqrt(2*n));
	return n == k*(k+1)/2;
}

bool ispent(long long n)
{
	long long k = long long(sqrt(double(2*n)/3)) + 1;
	return n == (k)*(3*k-1)/2;
}

long long hex(int n)
{
	return long long(n)*(2*long long(n)-1);
}

int main()
{
	int count = 0;
	int i = 1;
	time_t start = clock();
	while (count < 3) {
		long long k = hex(i);
		if (ispent(k)) {
			if (istrig(k)) {
				cout << i << ": " << k << endl;
				++count;
			}
		}
		++i;
	}
	time_t end = clock();
	double dur = double(end-start)/double(CLOCKS_PER_SEC);
	cout << "Time: " << dur << endl;
	pause();
}