#include "BigInt.h"

using namespace std;

BigInt pow(const BigInt& a, const BigInt& b)
{
	BigInt c("1");
	for (BigInt i; i < b; i += 1) {
		c *= a;
	}
	return c;
}

int digit_sum(const BigInt& bi) 
{
	string s = bi.str();
	istringstream iss(s);
	char ch;
	int sum = 0;
	while (iss.get(ch)) {
		if(isdigit(ch)) {
			sum += int(ch-'0');
		}
	}
	return sum;
}

int main() 
{
	BigInt big =  pow(BigInt("2"),BigInt("1000"));
	cout << big << ' ' << digit_sum(big);

	char stall;
	cin >> stall;
}