/*
	Bruce Zheng
	Problem 038
	4/9/13

	Since the concatenated product of 9 and (1,2,3,4,5) is pandigital, we know that the largest
	concatenated product possible must begin with a 9, so we will only check candidates that begin
	with 9. Furthermore, since the concatenated product must have 9 digits, and 2,3,...,n times
	a d digit number starting with 9 will have a product of d+1 digits, we only want to consider
	d digit numbers where d + k(d+1) can equal 9. Only 1 + 5(2) and 4 + 1(5) work, and the one 
	digit case is covered in the problem introduction. Thus we only need to consider numbers 9ABC,
	where A, B, C, are digits and need to check if 2*9ABC + 100000*9ABC is pandigital.
*/

#include <iostream>
#include <cmath>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

bool ispan(int n) {
	bool check[10];
	check[0] = true;
	for (int i = 1; i < 10; ++i)
		check[i] = false;
	int i = 0;
	while (pow(10,i) <= n) {
		int k = (n/int(pow(10,i)))%10;
		if (check[k]) return false;
		else check[k] = true;
		++i;
	}
	return true;
}

int main() 
{
	int max = 0;
	for (int i = 9999; i > 9000; --i) {
		int conc = 100002*i; // concatenated product of 9ABC and (1,2);
		if (ispan(conc)) {
			max = conc;
			break;
		}
	}
	cout << max;
	pause();
}