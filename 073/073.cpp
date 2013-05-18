/*
	Bruce Zheng
	Problem 073
	5/18/2013

	Generate a range of numerator values for each d where numerator over d is between 1/3 and 1/2.
	For each numerator n, add to count if n and d are relatively prime. We determine relative 
	primeness by generating gcd using the euclidian algorithm.
*/

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

int gcd(int a, int b) {
	int r_1, r_2, r_3;
	if (a > b) {
		r_1 = a;
		r_2 = b;
	}
	else {
		r_1 = b;
		r_2 = a;
	}
	while (true) {
		r_3 = r_1%r_2;
		if (r_3 == 0) return r_2;
		else {
			r_1 = r_2;
			r_2 = r_3;
		}
	}
}

int main()
{
	time_t start = clock();
	int count = 0;
	for (int i = 4; i <= 12000; ++i) {
		int high = floor(double(i)/double(2));
		int low = ceil(double(i)/double(3));
		for (int j = low; j <= high; ++j) {
			if (gcd(j,i) == 1) ++count;
		}
	}
	cout << count << endl;
	time_t end = clock();
	cout << "TIME: " << double(end-start)/double(CLOCKS_PER_SEC) << endl;
	pause();
}