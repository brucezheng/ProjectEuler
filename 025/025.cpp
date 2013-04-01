/*
	Bruce Zheng
	Problem 025
	4/1/2013

	Simple brute force method, nothing fancy here
*/

#include <iostream>
#include "BigInt.h"

using namespace std;

void pause() 
{
	char ch;
	cin >> ch;
}

int main()
{
	int i = 2;
	BigInt last(1);
	BigInt curr(1);
	while (curr.length() < 1000) {
		BigInt temp = curr;
		curr += last;
		last = temp;
		++i;
	}

	cout << i << endl;
	cout << curr;

	pause();
}