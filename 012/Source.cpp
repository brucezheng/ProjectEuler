#include <iostream>
#include <cmath>

using namespace std;

int triangular(int n)
// nth triangular number
{
	return (n + 1) * n / 2;
}

int numDiv(int n)
// number of divisors of n
{
	int num = 0;
	int square_root = sqrt(n);
	for (int i = 1; i < square_root; ++i) {
		if (n % i == 0) num += 2;
	}
	if (n % square_root == 0) ++num;
	return num;
}

int main() 
{
	int i = 1;
	while (numDiv(triangular(i)) < 500) {
		++i;
	}
	cout << i << ' ' << triangular(i) << ' ' << numDiv(triangular(i));
	char stall;
	cin >> stall;
}