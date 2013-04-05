/*
	Bruce Zheng
	Problem 030
	4/5/2013

	Checking if a number is the sum of its digits to the fifth power is easy. The only difficulty 
	is determining what range to check. 9^5*6 < 999999, so after 9^5*6, the "power sum" of a number
	cannot possibly be equal to the number. This gives us the range (10,9^5*6).
*/

#include <iostream>
#include <cmath>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

int pow_sum(int n) 
{
	int result = 0;
	int i = 0;
	while(pow(10,i) < n) {
		int k = int(n/pow(10,i))%10;
		result += pow(k,5);
		++i;
	}
	return result;
}

int main()
{
	int sum = 0;
	for (int i = 10; i < 354294; ++i) {
		if (i == pow_sum(i)) {
			cout << i << endl;
			sum += i;
		}
	}
	cout << sum << endl;
	pause();
}