/*
	Bruce Zheng
	Problem 050
	4/14/2013

	We construct both an array of bools of all numbers in the range as well as a vector of primes
	over the range. We can use the vector to find the nth prime easily, but we can use the array
	to quickly check if a number is a prime. We need both in the algorithm.

	The basic strategy is to check every possible sum of n consecutive primes below one million
	and track the prime that is the sum of the longest series possible.
*/

#include <iostream>
#include <vector>

using namespace std;

void pause() {
	char ch;
	cin >> ch;
}

int main()
{
	const int size = 1000001;
	// true = prime
	bool *a = new bool[size];
	// initializing stack
	a[0] = false;
	a[1] = false;
	for (int i = 2; i < size; ++i)
		a[i] = true;
	// getting prime numbers
	for (int i = 2; i < size; ++i)
		if (a[i])
			for (int j = 2; j <= (size-1)/i; ++j) 
				a[j*i] = false;
	// adding primes to a vector
	vector<int> v;
	for (int i = 0; i < size; ++i) {
		if (a[i]) v.push_back(i);
	}
	// finding largest chain
	int n = 1;
	int max = 0;
	// base is the first sequence sum for n
	int base = 2;
	while (base < size) {
		int seq = base;
		int i = 0;
		while (seq < size) {
			if (a[seq]) {
				//cout << n << ' ';
				//cout << seq << endl;
				max = seq;
				break;
			}
			seq = seq+v[n+i]-v[i];
			++i;
		}
		base += v[n];
		++n;
	}
	cout << max;
	pause();
}