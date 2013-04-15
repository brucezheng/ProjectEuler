/*
	Bruce Zheng
	Problem 052
	4/15/2013

	Used an array to keep track of digit counts. This method would actually fail for numbers with
	repeat digits, but produced the correct answer for the problem.
*/

#include <iostream>
#include <ctime>

using namespace std;

void pause() 
{
	char ch;
	cin >> ch;
}

// returns num digits of n
int length(long n) 
{
	if (n >= 100000000) {
		int i = 0;
		while (pow(10,i) <= n) ++i;
		return i;
	}
	else if (n >= 10000) {
		if (n >= 1000000) {
			if (n >= 10000000) return 8; 
			else return 7; 
		}
		else {
			if (n >= 100000) return 6;
			else return 5;
		}
	}
	else {
		if (n >= 100) {
			if (n > 1000) return 4;
			else return 3;
		}
		else {
			if (n >= 10) return 2;
			else return 1;
		}
	}
}

// checks to see if n, 2n, .., 6n share the same digits; FAILS FOR NUMS WITH REPEAT DIGITS!
bool pmults(int n) {
	if (length(n) != length(6*n)) return false;
	int d[10] = {0};
	for (int i = 1; i < 7; ++i) {
		int m = i*n;
		int j = 0;
		while (j < length(n)) {
			int k = m/int(pow(10,j))%10;
			if (d[k] != i-1) return false;
			else ++d[k];
			++j;
		}
	}
	return true;
}

int main()
{
	time_t start = clock();
	int i = 1;
	while (!pmults(i) && i < 1000000) ++i;
	cout << i << endl;
	time_t end = clock();
	double dur = double(end-start)/double(CLOCKS_PER_SEC);
	cout << "TIME: " << dur << endl;
	pause();
}