/*
	Bruce Zheng
	Problem 049
	4/13/2013

	For this problem, I used a map to store all permutations of a number that are greater than
	that number. Then, we check every possible permutation to see if 1) that permutation is also
	prime 2) the next element in the arithmetic sequence is prime and 4 digits long and 3) if that
	next element is also a permutation of our original number. If all three conditions are met, we
	print out the answer and increase the count. This algorithm loops through all possible 4 digit
	primes until two valid sequences are found.
*/

#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

// every permutation of the digits of n greater than n
map<int,int> perm(int n) {
	int d[4];
	d[0] = n/1000;
	d[1] = n/100%10;
	d[2] = n/10%10;
	d[3] = n%10;

	map<int,int> result;
	while (next_permutation(d,d+4)) {
		int k = d[0]*1000+d[1]*100+d[2]*10+d[3];
		result.insert(pair<int,int>(k,k));
	}
	return result;
}

int main()
{
	const int size = 10001;
	// 0 = not prime, 1 = prime, 2 = circular prime
	bool *p = new bool[size];
	// initializing stack
	p[0] = false;
	p[1] = false;
	for (int i = 2; i < size; ++i)
		p[i] = true;
	// getting prime numbers
	for (int i = 2; i < size; ++i)
		if (p[i])
			for (int j = 2; j <= (size-1)/i; ++j) 
				p[j*i] = false;
	// find permutable primes
	int count = 0;
	int i = 1000;
	while (count < 2 && i < size) {
		if (p[i]) {
			map<int,int>& m = perm(i);
			for (map<int,int>::iterator j = m.begin(); j != m.end(); ++j) {
				int& k = j->second;
				if (p[k]) {
					int diff = k-i;
					if (k+diff < size && p[k+diff] && m.find(k+diff) != m.end()) {
						++count;
						cout << i << k << k+diff << endl;
					}
				}
			}
		}
		++i;
	}
	pause();
}