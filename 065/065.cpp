/*
	Bruce Zheng
	Problem 065
	5/17/2013

	Generate all denominator values and keep in a vector, then iteratively generate the simplified
	fraction from bottom up. Used bigint v2.
*/

#include <iostream>
#include <ctime>
#include <vector>

#include "BigIntv2.h"

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

int digitsum (BigInt b) {
	string str = b.str();
	int result = 0;
	for (int i = 0; i < str.length(); ++i) {
		result += int(str[i]-'0');
	}
	return result;
}

int main()
{
	time_t start = clock();
	vector<int> den;
	den.push_back(2);
	for (int i = 2; i <= 100; ++i) {
		if(i%3 == 0) den.push_back((i/3)*2);
		else den.push_back(1);
	}
	BigInt top = den[den.size()-1];
	BigInt bot = 1;
	for (int i = den.size()-2; i >= 0; --i) {
		BigInt temp = top;
		top = BigInt(den[i])*top+bot;
		bot = temp;
	}
	cout << top << '/' << bot << endl;
	cout << digitsum(top) << endl;
	time_t end = clock();
	cout << "TIME: " << double(end-start)/double(CLOCKS_PER_SEC) << endl;
	pause();
}