/*
	Bruce Zheng
	Problem 034
	4/5/2013

	Not much to this solution. The max the number could be is 9!*7 = 2540160. We just check
	all possible numbers below that.
*/

#include <iostream>
#include <cmath>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

int fact_sum(int n)
{
	int result = 0;
	int i = 0;
	while(pow(10,i) <= n) {
		int k = int(n/pow(10,i))%10;
		int inc;
		switch(k) {
			case 0: inc = 1; break;
			case 1: inc = 1; break;
			case 2: inc = 2; break;
			case 3: inc = 6; break;
			case 4: inc = 24; break;
			case 5: inc = 120; break;
			case 6: inc = 720; break;
			case 7: inc = 5040; break;
			case 8: inc = 40320; break;
			case 9: inc = 362880; break;
			default: cerr << "wtf??"; break;
		}
		result += inc;
		++i;
	}
	return result;
}

int main()
{
	int sum = 0;
	for (int i = 10; i <= 2540160; ++i) {
		if (i == fact_sum(i)) {
			cout << i << endl;
			sum += i;
		}
	}
	cout << sum << endl;
	pause();
}