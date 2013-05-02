/*
	Bruce Zheng
	Problem 058
	5/1/2013
*/

#include <iostream>
#include <ctime>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

bool isprime(int n) {
	int m = sqrt(n);
	for (int i = 2; i <= m; ++i)
		if (n%i == 0) return false;
	return true;
}

int main()
{
	time_t start = clock();
	int i = 3;
	int j = 0;
	int level = 1;
	int count = 0;
	double prop = 1;
	while (prop > 0.1) {
		if (isprime(i)) ++count;
		if (j == 3) {
			j = 0;
			prop = double(count)/double(4*level+1);
			++level;
		}
		else ++j;
		i += 2*level;
	}
	time_t end = clock();
	cout << prop << ' ' << 2*level-1 << endl;
	cout << "TIME: " << double(end-start)/double(CLOCKS_PER_SEC) << endl;
	pause();
}