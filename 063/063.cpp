/*
	Bruce Zheng
	Problem 063
	4/18/2013

	Basic bruteforce method using BigInt. Pretty slow, considering we only check 22 powers.
*/

#include <iostream>
#include <cmath>
#include <ctime>

#include "BigIntv2.h"

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

BigInt longpower(int n, int m)
{
	BigInt result(1);
	for (int i = 0; i < m; ++i) {
		result = result * BigInt(n);
	}
	return result;
}

int main()
{
	time_t start = clock();
	int valids = 0;
	bool done = false;
	int i = 1;
	while (!done) {
		int j = 2;
		int length = 1;
		int diff = 0;
		while (length <= i) {
			if (length == i) ++diff;
			length = longpower(j,i).str().size();
			++j;
		}
		if (diff == 0) done = true;
		valids += diff;
		++i;
	}
	time_t end = clock();
	double dur = double(end-start)/double(CLOCKS_PER_SEC);
	cout << valids << endl << "TIME: " << dur << endl;
	pause();
}