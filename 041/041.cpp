/*
	Bruce Zheng
	Problem 041
	4/10/2013

	The digits of an 8 and 9 digit pandigital number would add up to 36 and 45 respectively, meaning
	they would be divisible by 9 and definitely not prime. Therefore, this algorithm begins at 
	7,654,321 and seeks the first pandigital prime.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

bool ispan(int n) 
{
	int len = 0;
	while (pow(10,len) <= n) {
		++len;
	}
	// check[i] represents if n contains i
	bool check[10];
	check[0] = true;
	for (int i = 1; i < 10; ++i)
		check[i] = false;
	int i = 0;
	while (pow(10,i) <= n) {
		int k = (n/int(pow(10,i)))%10;
		if (k > len) return false;
		// if k is already in n then we have duplicates
		if (check[k]) return false;
		else check[k] = true;
		++i;
	}
	return true;
}

bool isprime(int n) 
{
	if (n < 2) return false;
	// check all possible factors up to sqrt
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n%i == 0) return false;
	}
	return true;
}

int main()
{
	int max;
	for (int i = 7654321; i > 0; --i) {
		if (ispan(i)) {
			if (isprime(i)) {
				max = i;
				break;
			}
		}
	}
	cout << max;
	pause();
}