/*
	Bruce Zheng
	Problem 053
	4/15/2013

	Since n choose m = n choose (n-m), and n choose k > n choose m if k > m and k < (n-m), we only
	need to find the first value m that is over one million for each n from 1 to 100, and we know 
	that all the values from n to (n-m) should produce values over one million.
*/

#include <iostream>
#include <ctime>

using namespace std;

void pause() 
{
	char ch;
	cin >> ch;
}

// returns n choose m
long long choose(int n, int m) {
	if (n-m < 0) return 0;
	else if (m > n/2) return choose(n,n-m);
	else if (m == 0) return 1;
	long long num = 1;
	long long den = 1;
	for (int i = 1; i <= m; ++i) {
		num *= (n-m)+i;
		den *= i;
	}
	return num/den;
}

int main()
{
	time_t start = clock();
	int count = 0;
	for (int i = 1; i <= 100; ++i) {
		for (int j = 0; j <= ceil(double(i)/double(2)); ++j) {
			if (choose(i,j) > 1000000) {
				count += i+1-2*j;
				break;
			}
		}
	}
	cout << count << endl;
	time_t end = clock();
	double dur = double(end-start)/double(CLOCKS_PER_SEC);
	cout << "TIME: " << dur << endl;
	pause();
}