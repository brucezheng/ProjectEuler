/*
	Bruce Zheng
	Problem 040
	4/10/13

	Represent irrational fraction up to millionth digit using an array and filling with digits of
	consecutive numbers.
*/

#include <vector>
#include <iostream>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

int length(int n) {
	if (n >= 100000) return 6;
	else if (n >= 10000) return 5;
	else if (n >= 1000) return 4;
	else if (n >= 100) return 3;
	else if (n >= 10) return 2;
	else return 1;
}

int main()
{
	int* seq = new int[1000010];
	int count = 0;
	int i = 1;
	while (count < 1000000) {
		for (int j = length(i); j > 0; --j) {
			int k = i/int(pow(10,j-1))%10;
			seq[count] = k;
			++count;
		}
		++i;
	}
	int c = seq[0] * seq[9] * seq[99] * seq[999] * seq[9999] * seq[99999] * seq[999999];
	cout << c;
	pause();
}