/*
	Bruce Zheng
	Problem 069
	5/1/2013

	Using Euler's product formula, totient(n) = n*pi(1-1/p) for all prime p that divide n. 
	Therefore n/totient(n) = 1/pi(1-1/p) = pi(p/p-1). The largest value of n/totient(n)
	then will be some n = 2*3*5*7....p_k. Therefore we need to find the largest consecutive
	prime product that less than 1 million.
*/

#include <iostream>
#include <ctime>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

int main() {
	time_t start = clock();
	bool* p = new bool[100];
	p[0] = false;
	p[1] = false;
	for (int i = 2; i < 100; ++i) 
		p[i] = true;
	for (int i = 2; i < 100; ++i) {
		if (p[i]) {
			int k = 2*i;
			while (k < 100) {
				p[k] = false;
				k += i;
			}
		}
	}
	int prod = 1;
	int i = 1;
	while (i < 100) {
		if (p[i])
			prod *= i;
		if (prod > 1000000) 
			break;
		++i;
	}
	prod /= i;
	cout << prod << ' ' << i << endl;
	time_t end = clock();
	cout << "TIME: " << double(end-start)/double(CLOCKS_PER_SEC) << endl;
	pause();
}