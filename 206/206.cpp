/*
	Bruce Zheng
	Problem 206
	5/21/2013

	We know that the squared number must end with 0; we just have to check every tenth number whose
	square is over 10^19.
*/

#include <iostream>
#include <ctime>

using namespace std;

static int low = ceil(sqrt(double(1020304050607080900)));

void pause()
{
	char ch;
	cin >> ch;
}

bool check(long long n)
{
	int i = 0;
	if (n%10 != i) return false;
	i = 9;
	while (i > 0) {
		n /= 100;
		if (n%10 != i) return false;
		--i;
	}
	return true;
}

int main()
{
	time_t start = clock();
	int i = low;
	//low isnt a multiple of 10
	while (i%10 != 0) ++i;
	//check every int ending w/ 0
	while (!check(long long(i)*long long(i))) i+= 10;
	cout << i << endl << long long(i)*long long(i) << endl;
	time_t end = clock();
	cout << "TIME: " << double(end-start)/double(CLOCKS_PER_SEC);
	pause();
}