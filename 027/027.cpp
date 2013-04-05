/*
	Bruce Zheng
	Problem 027
	4/4/2013

	Fairly straightforward solution, checking all possible polinomials that would produce positive
	numbers.
*/

#include <iostream>
#include <cmath>
#include <iostream>

using namespace std;

void pause() 
{
	char ch;
	cin >> ch;
}

bool isprime(int i)
{
	if (i < 2) return false;
	for (int j = 2; j <= sqrt(i); ++j) {
		if (i%j == 0) return false;
	}
	return true;
}

int numprimes(int a, int b) 
{
	int i = 0;
	while (isprime(i*i + a*i + b))
		++i;
	return i;
}

int main() 
{
	int max = 0;
	int temp;
	int a_most = 0;
	int b_most = 0;
	for (int a = 1; a <= 1000; ++a) {
		for (int b = 1; b < a; ++b) {
			temp = numprimes(a,-b);
			if (temp > max) {
				max = temp;
				a_most = a;
				b_most = -b;
			}
			temp = numprimes(a,b);
			if (temp > max) {
				max = temp;
				a_most = a;
				b_most = b;
			}
		}
		for (int b = a; b <= 1000; ++b) {
			temp = numprimes(a,b);
			if (temp > max) {
				max = temp;
				a_most = a;
				b_most = b;
			}
			temp = numprimes(-a,b);
			if (temp > max) {
				max = temp;
				a_most = -a;
				b_most = b;
			}
		}
	}
	cout << max << ' ' << a_most << ' ' << b_most << ' ' << a_most*b_most;
	pause();
}