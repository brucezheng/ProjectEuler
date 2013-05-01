/*
	Bruce Zheng
	Problem 057
	5/1/2013

	Let the nth approximation of 2^(1/2) = 1 + a_n. 
	a_(n+1) = 1/(2+a_n) -> 2+a_n = 1/a_(n+1). If we let a_n = k_n/m_n, then
	(2m_n + k_n)/m_n = m_(n+1)/k_(n+1) -> a_(n+1) = m_n/(2m_n + k_n).
	
	In fact, we know this is the reduced form of a_(n+1), since k_n/m_n is the reduced form of
	a_n, meaning that m_n and k_n are relatively prime. Therefore, 2m_n + k_n should be relatively
	prime to k_n.

	We can use this to determine the approximation of 2^(1/2). We also will truncate the numerator
	and denominator values of a_n if they get too large.
*/

#include <iostream>
#include <ctime>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

// returns num digits of n
int length(long n) 
{
	if (n >= 100000000) 
	{	int i = 0;
		while (pow(10,i) <= n) ++i;
		return i; }
	else if (n >= 10000)
	{	if (n >= 1000000) 
		{	if (n >= 10000000) return 8; 
			else return 7; }
		else 
		{	if (n >= 100000) return 6;
			else return 5; } }
	else 
	{	if (n >= 100) 
		{	if (n > 1000) return 4;
			else return 3; }
		else 
		{   if (n >= 10) return 2;
			else return 1; } }
}

int main()
{
	time_t start = clock();
	int k = 1;
	int m = 2;
	int count = 0;
	for (int i = 1; i < 1001; ++i) {
		if (length(k) > 7) {
			k /= 1000;
			m /= 1000;
		}
		if (length(k+m) > length(m)) ++count;
		int temp = 2*m + k;
		k = m;
		m = temp;
	}
	time_t end = clock();
	double dur = double(end-start)/double(CLOCKS_PER_SEC);
	cout << count << endl;
	cout << "TIME: " << dur << endl;
	pause();

}