/*
	Bruce Zheng
	Problem 055
	4/18/2013

	Using the second version of my bigint class, I created simple functions to check for a
	palindrome and produce the reverse of a number. Checking is somewhat simple.
*/

#include <iostream>
#include <string>
#include <ctime>

#include "BigIntv2.h"

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

BigInt reverse(const BigInt& big) {
	string& fwd = big.str();
	string rev;
	for (int i = 0; i< fwd.length(); i++) {
		rev = fwd[i] + rev;
	}
	BigInt result(rev);
	return result;
}

bool checkpal(string s) {
	for (int i = 0; i < s.size()/2; ++i) {
		if (s[i] != s[s.size()-1-i]) return false;
	}
	return true;
}

int main()
{
	time_t start = clock();
	int count = 0;
	for (int i = 1; i < 10000; ++i) {
		BigInt big(i);
		int found = false;
		for (int j = 0; j < 50; ++j) {
			big = big + reverse(big);
			if (checkpal(big.str())) {
				found = true;
				break;
			}
		}
		if (!found) {
			++count;
			cout << i << ' ';
		}
	}
	time_t end = clock();
	double dur = double(end-start)/double(CLOCKS_PER_SEC);
	cout << endl << count << endl;
	cout << "TIME: " << dur << endl;
	pause();
}