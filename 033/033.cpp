/*
	Bruce Zheng
	Problem 033
	4/6/2013

	For each possible permutation of two unique digits a and b, check to see if ak/bk, ak/kb, 
	ka/bk, or ka/kb is equal to a/b (since a/b needs to be under 1, we only check values of b
	greater than a). Then find the product of all these numbers and simplify.
*/

#include <iostream>

using namespace std;

typedef pair<int,int> frac;

void pause () 
{
	char ch;
	cin >> ch;
}

ostream& operator<<(ostream& out, const frac f) 
{
	out << f.first << '/' << f.second;
	return out;
}

frac reduced(frac f) 
{
		int top = f.first;
		int bot = f.second;
		int& min = (top > bot ? bot : top);
		int i = 2;
		while (i <= min) {
			while (top%i == 0 && bot%i == 0) {
				top /= i;
				bot /= i;
			}
			++i;
		}
		return frac(top,bot);
}

bool comp(const frac& x, const frac& y) 
{
	return reduced(x) == reduced(y);
}

int main ()
{
	frac product(1,1);
	for (int a = 1; a < 10; ++a) {
		for (int b = a+1; b < 10; ++b) {
			for (int k = 1; k < 10; ++k) {
				if (k != b && k != a) {
					if (comp(frac(a,b),frac(10*a+k,10*b+k))) {
						product.first *= a;
						product.second *= b;
						cout << frac(10*a+k,10*b+k) << endl;
					}
					if (comp(frac(a,b),frac(10*a+k,10*k+b))) {
						product.first *= a;
						product.second *= b;
						cout << frac(10*a+k,10*k+b) << endl;
					}	
					if (comp(frac(a,b),frac(10*k+a,10*b+k))) {
						product.first *= a;
						product.second *= b;
						cout << frac(10*k+a,10*b+k) << endl;
					}
					if (comp(frac(a,b),frac(10*k+a,10*k+b))) {
						product.first *= a;
						product.second *= b;
						cout << frac(10*k+a,10*k+b) << endl;
					}	
				}
			}
		}
	}
	cout << endl << reduced(product);
	pause();
}