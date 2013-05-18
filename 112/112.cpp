/*
	Bruce Zheng
	Problem 112
	5/18/2013
*/

#include <iostream>
#include <ctime>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

bool isbouncy(long long n)
{
	// n keeps track of last digit, m is current digit
	bool inc = true, dec = true;
	int k = n%10;
	int m;
	n /= 10;
	while (n > 0) {
		m = n%10;
		if (m > k) inc = false;
		else if (m < k) dec = false;
		if (!inc && !dec) return true;
		k = m;
		n /= 10;
	}
	return false;
}

int main()
{
	time_t start = clock();
	bool done = false;
	int i = 1;
	// ct = num bouncy numbers
	int ct = 0;
	while (!done) {
		if (isbouncy(i)) ++ct;
		if (i % 100 == 0  && double(ct)/double(i) == 0.99) break;
		++i;
	}
	cout << i << endl;
	time_t end = clock();
	cout << "TIME: " << double(end-start)/double(CLOCKS_PER_SEC) << endl;
	pause();
}