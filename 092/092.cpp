/*
	Bruce Zheng
	Problem 092
	4/28/2013
*/

#include <iostream>
#include <ctime>

using namespace std;

int digit_sqr_sum(int n)
{
	int result = 0;
	while (n > 0) {
		int k = n%10;
		result += k*k;
		n /= 10;
	}
	return result;
}

void pause()
{
	char ch;
	cin >> ch;
}

int main()
{
	time_t start = clock();
	int _1count = 0;
	int _89count = 0;
	for (int i = 1; i <= 10000000; ++i) {
		int k = i;
		bool done = false;
		while (!done) {
			if (k == 89) {
				done = true;
				++_89count;
			}
			else if (k == 1) {
				done = true;
				++_1count;
			}
			else {
				k = digit_sqr_sum(k);
			}
		}
	}
	time_t end = clock();
	cout << "1 count: " << _1count << " 89 count: " << _89count << endl;
	cout << "TIME: " << double(end-start)/double(CLOCKS_PER_SEC) << endl;
	pause();
}