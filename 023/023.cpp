/*
	Bruce Zheng
	Problem 023
	3/30/2013

	First we construct a vector {a_1,...,a_n} of abundant numbers below 28123. Using a vector of
	booleans which tell us if a number can be expressed as a sum of two abundant nubmers, we can
	find all sum values of our abundant numbers and flag their respective numbers in this bool 
	vector. Using that, we can easily find all numbers that aren't a sum of two abundant numbers
	and sum them

	The function divSum is taken from problem 021. 
*/

#include <iostream>
#include <vector>

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
	for (int i = 2; i <= root; ++i) {
		if (n % i == 0) {
			result += (i + n/i);
		}
	}
	// only one additional divisor if n is a perfect square
	if (root*root == n) result -= root;
	return result;
}

// is n abundant?
bool abundant(int n)
{
	return divSum(n) > n;
}

int main()
{
	// generate abundant numbers
	vector<int> abun;
	for (int i = 1; i <= 28123; ++i) {
		if (abundant(i)) 
			abun.push_back(i);
	}

	// isSum[n] will refer to the truth value for n, not n-1!
	vector<bool> isSum(28124,false);

	// determine all possible sums
	for (int i = 0; i < abun.size(); ++i) {
		for (int j = i; j < abun.size(); ++j) {
			if (abun[i]+abun[j] > 28123) 
				break;
			else 
				isSum[abun[i]+abun[j]] = true;
		}
	}

	// determining sum of all deficit numbers
	long sum = 0;
	for (int i = 1; i <= 28123; ++i) {
		if(!isSum[i])
			sum += i;
	}
	cout << sum;

	pause();
}