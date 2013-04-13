/*
	Bruce Zheng
	Problem 046
	4/12/2013

	Two loops used; one to check every odd number and one to check composite numbers to see if they
	fit Goldbach's conjecture
*/

#include <iostream>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

bool isprime(int n)
{
	for (int i = 2; i <= sqrt(n); ++i)
		if (n%i == 0) return false;
	return true;
}

int main()
{
	bool done = false;
	int i = 1;
	while (!done && i < 1000000) {
		if (!isprime(i)) {
			int j = 1;
			done = true;
			while (2*j*j <= i) {
				if (isprime(i-2*j*j)) {
					//cout << i << ": " << i-2*j*j << " + " << "2(" << j << "^2)" << endl;
					done = false;
					break;
				}
				++j;
			}
		}
		if (done) cout << i << endl;
		i+=2;
	}
	pause();
}