/*
	Bruce Zheng
	Problem 028
	4/4/2013

	The summation series looks like 1 + (3 + 5 + 7 + 9) + (13 + 17 + 21 + 25) + (31 + 37 + 43 + 49)
	and so forth, which produces a noticable pattern that each term is n-1 more than the previous
	for the four terms of each nth ring of our spiral. Thus we simply apply this to n rings
*/

#include <iostream>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

int main()
{
	//1001x1001 has 500 rings
	int sum = 1;
	int k = 1;
	for(int i = 0; i < 500; ++i) {
		for (int j = 0; j < 4; ++j) {
			k += 2*(i+1);
			sum += k;
		}
	}
	cout << sum << endl;
	pause();
}