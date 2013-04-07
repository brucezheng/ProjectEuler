/*
	Bruce Zheng
	Problem 036
	4/7/2013

	Wrote a function that can determine if an integer is a palindrome in any base, by scanning the digits
	of that number in the correct base from the outside in. Then just check every number avaliable using
	that algorithm.
*/

#include <iostream>
#include <cmath>

using namespace std;

void pause() 
{
	char ch;
	cin >> ch;
}

bool ispalin(int n, int base) 
{
	int digits = 0;
	while(pow(base,digits) <= n) {
		++digits;
	}
	for (int i = 0; i <= digits/2; ++i) {
		int k = int(n/pow(base,digits-1-i))%base;
		int j = int(n/pow(base,i))%base;
		if (k != j) return false;
	}
	return true;
}

int main() 
{
	int sum = 0;
	for (int i = 0; i < 1000000; ++i) {
		if (ispalin(i,10)) {
			if (ispalin(i,2)) {
				cout << i << endl;
				sum += i;
			}
		}
	}
	cout << endl << sum;
	pause();
}