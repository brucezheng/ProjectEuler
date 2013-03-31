/* 
	Bruce Zheng
	Problem 020
	3/30/2013

	Finds sum of digits of large factorial value. Used BigInt class from previously implemented problems, also added increment/decrement operators.
	Algorithm to compute sum of digits also taken from problem 016.
*/

#include "BigInt.h"

// returns n!
BigInt fact (BigInt n) 
{
	BigInt result(1);
	for (BigInt i(1); i <= n; ++i) result *= i;
	return result;
}

// returns sum of digits of n
int digit_sum(const BigInt& n) 
{
	string s = n.str();
	istringstream iss(s);
	char ch;
	int result = 0;
	while (iss.get(ch)) {
		if(isdigit(ch)) {
			result += int(ch-'0');
		}
	}
	return result;
}

int main () 
{
	BigInt n = fact(100);
	cout << n << endl << digit_sum(n);

	char stall;
	cin >> stall;
}