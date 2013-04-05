/*
	Bruce Zheng
	Problem 030
	4/5/2013

	Heavily nested loops used to find every possible combination. Number of ways to make n pence is
	number of ways to make n pence without any 2 pound notes plus number of ways to make n-200
	pence without any n pence note, etc. Number of ways to make n pence wihtout any 2 pound notes 
	is the number of ways to make n pence without any 2 pound notes plus number of ways to make n -
	100 pence without either 2 or 1 pound notes, so on and so on until we find all possible
	combinations. Quite unreadable code, but relatively quick performance.
*/

#include <iostream>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

int numCombo(int total)
{
	int result = 0;
	// this abomination loop system systematically finds every combination of coins
	for (int i_a = 0; i_a <= total/200; ++i_a) {
		int rem_a = total-i_a*200;
		for (int i_b = 0; i_b <= rem_a/100; ++i_b) {
			int rem_b = rem_a-i_b*100;
			for (int i_c = 0; i_c <= rem_b/50; ++i_c) {
				int rem_c = rem_b-i_c*50;
				for (int i_d = 0; i_d <= rem_c/20; ++i_d) {
					int rem_d = rem_c-i_d*20;
					for (int i_e = 0; i_e <= rem_d/10; ++i_e) {
						int rem_e = rem_d-i_e*10;
						for (int i_f = 0; i_f <= rem_e/5; ++i_f) {
							int rem_f = rem_e-i_f*5;
							result += 1+(rem_f/2);
						}
					}
				}
			}
		}
	}
	return result;
}

int main()
{
	cout << numCombo(200);
	pause();
}