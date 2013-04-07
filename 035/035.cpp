/*
	Bruce Zheng
	Problem 035
	4/6/2013

	First, find all primes using the sieve of eratosthenes. Mark all circular primes and sum them.
*/

#include <iostream>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

int main()
{
	const int size = 1000001;
	// 0 = not prime, 1 = prime, 2 = circular prime
	int *p = new int[size];
	// initializing stack
	p[0] = 0;
	p[1] = 0;
	for (int i = 2; i < size; ++i) {
		p[i] = 1;
	}
	// getting prime numbers
	for (int i = 2; i < size; ++i) {
		if (p[i] == 1) {
			for (int j = 2; j <= (size-1)/i; ++j) {
				p[j*i] = 0;
			}
		}
	}
	// finding circular primes
	int count = 0;
	for (int i = 1; i < size; ++i) {
		if (p[i] == 1) {
			// determine number of rotations to check (num of digits - 1)
			int rot = 0;
			while (pow(10,rot+1) <= i) {
				++rot;
			}
			// k is a rotation of i
			int k = i;
			bool circular = true;
			for(int j = 0; j < rot; ++j) {
				k = (k/10)+pow(10,rot)*(k%10);
				if (p[k] == 0) circular = false;
			}
			if (circular) {
				k = i;
					for(int j = 0; j < rot+1; ++j) {
						p[k] = 2;
						k = (k/10)+pow(10,rot)*(k%10);
					}
				cout << i << ' ';
				++count;
			}
		}
		else if(p[i] == 2) {
			cout << i << ' ';
			++count;
		}
	}
	cout << endl << count;
	pause();
}