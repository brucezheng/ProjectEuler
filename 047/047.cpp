/*
	Bruce Zheng
	Problem 047
	4/12/2013

	Efficiency note: placing the while loop within the if block in primefacts reduced runtime by
	fifty percent.
*/

#include <iostream>
#include <ctime>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

// returns how many prime factors n has
int primefacts(int n)
{
	int i = 2;
	int result = 0;
	while(i <= n) {
		if (n%i == 0) {
			++result;
			n /= i;
			while (n%i == 0) n /= i;
		}
		++i;
	}
	return result;
}

int main()
{
	time_t start = clock();
	int count = 0;
	int i = 1;
	while (count < 4) {
		// increase count for consecutive numbers
		if (primefacts(i) == 4) {
			//cout << i << endl;
			++count;
		}
		// reset count otherwise
		else count = 0;
		++i;
	}
	time_t end = clock();
	double dur = double(end-start)/double(CLOCKS_PER_SEC);
	cout << i-4 << endl;
	cout << "TIME: " << dur << endl;
	pause();
}