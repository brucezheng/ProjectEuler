/*
	Bruce Zheng
	Problem 021
	3/30/2013

	Simple algorithm for finding the sum of proper divisors of n by just checking ints that divide 
	below n^{1/2}. Amicability is easy to check after that point and a simple loop finds all 
	amicable numbers below 10,000
*/

#include <iostream>

using namespace std;

// avoid quitting terminal in windows
void pause() 
{
	char stall;
	cin >> stall;
}

// sum of all proper divsors of n
int divSum(int n) 
{
	int root = int(sqrt(n));
	int result = 0;
	if (n != 1) result += 1; // 1 is always a proper divisor unless n = 1
	for (int i = 2; i < root; ++i) {
		if (n % i == 0) {
			result += (i + n/i);
		}
	}
	// only one additional divisor if n is a perfect square
	if (root*root == n) result += root;
	return result;
}

// is n amicable?
bool amicable(int n) 
{
	return n != divSum(n) && n == divSum(divSum(n));
}

#include <iostream>

int main ()
{
	int sum = 0;
	for (int i = 2; i < 10000; ++i) {
		if (amicable(i)) sum += i;
	}
	cout << sum;
	
	pause();
	return 0;
}
