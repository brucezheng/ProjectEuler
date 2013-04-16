/*
	Bruce Zheng
	Problem 056
	4/16/2013

	Same implementation as problem 020; only guess n^m for n,m = 90,91,...,100. Runtime extremely
	slow due to implementation of BigInt.
*/

#include "BigInt.h"

#include <iostream>
#include <ctime>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

BigInt pow(const BigInt& a, const BigInt& b)
{
	BigInt c("1");
	for (BigInt i; i < b; i += 1) {
		c *= a;
	}
	return c;
}

int digit_sum(const BigInt& bi) 
{
	string s = bi.str();
	istringstream iss(s);
	char ch;
	int sum = 0;
	while (iss.get(ch)) {
		if(isdigit(ch)) {
			sum += int(ch-'0');
		}
	}
	return sum;
}

int main()
{
	time_t start = clock();
	int max = 0;
	for (int i = 90; i <100; ++i) {
		cout << i << ' ';
		for (int j = 90; j < 100; ++j) {
			int temp = digit_sum(pow(BigInt(i),BigInt(j)));
			if (temp > max) max = temp;
		}
	}
	time_t end = clock();
	double dur = double(end-start)/double(CLOCKS_PER_SEC);
	cout << max << endl;
	cout << "TIME: " << dur << endl;
	pause();
}