/*
	Bruce Zheng
	Problem 043
	4/12/2013

	Included are two methods of generating all 10 digit pandigital numbers. Checking for the cases
	the easier part of the problem.
*/

#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

// recursive, 45 sec method
void genpan(vector<long long>& v, long long seed = 0) 
{
	int d[10] = {0};
	int i = 0;
	while (long long(pow(10,i)) <= seed) {
		int k = seed/long long(pow(10,i))%10;
		d[k] = 1;
		++i;
	}
	if (i == 10) v.push_back(seed);
	else {
		if (i != 0) {
			if (d[0] != 1) genpan(v,seed*10);
		}
		for (int j = 1; j < 10; ++j) {
			if (d[j] != 1) genpan(v,seed*10+j);
		}
	}
}

// iterative HUGEASS METHOD, 3 seconds!
void altgenpan(vector<long long>& v) 
{
	for (int a = 1; a < 10; ++a) {

	for (int b = 0; b < 10; ++b) {
		if (b != a) {

	for (int c = 0; c < 10; ++c) {
		if (c != b && c != a) {

	for (int d = 0; d < 10; ++d) {
		if (d != c && d != b && d != a) {

	for (int e = 0; e < 10; ++e) {
		if (e != d && e != c && e != b && 
			e != a) {

	for (int f = 0; f < 10; ++f) {
		if (f != e && f != d && f != c && 
			f != b && f != a) {

	for (int g = 0; g < 10; ++g) {
		if (g != f && g != e && g != d && 
			g != c && g != b && g != a) {

	for (int h = 0; h < 10; ++h) {
		if (h != g && h != f && h != e && 
			h != d && h != c && h != b && 
			h != a) {

	for (int i = 0; i < 10; ++i) {
		if (i != h && i != g && i != f && 
			i != e && i != d && i != c && 
			i != b && i != a) { 

	for (int j = 0; j < 10; ++j) {
		if (j != i && j != h && j != g && 
			j != f && j != e && j != d && 
			j != c && j != b && j != a)
				v.push_back(1000000000*long long(a)+100000000*long long(b)
				+10000000*long long(c)+1000000*long long(d)+100000*long long(e)
				+10000*long long(f)+1000*long long(g)+100*long long(h)
				+10*long long(i)+long long(j));
	} } } } } } } } } } } } } } } } } }
}

bool test(long long n) 
{
	if ((n/1000000%1000)%2!=0) return false;
	if ((n/100000%1000)%3!=0)  return false;
	if ((n/10000%1000)%5!=0)   return false;
	if ((n/1000%1000)%7!=0)    return false;
	if ((n/100%1000)%11!=0)	   return false;
	if ((n/10%1000)%13!=0)	   return false;
	if ((n%1000)%17!=0)		   return false;
	return true;
}

int main()
{
	long long sum = 0;
	vector<long long> v;
	time_t t_1 = clock();
	altgenpan(v);
	time_t t_2 = clock();
	for (int i = 0; i < v.size(); ++i) {
		if (test(v[i])) {
			cout << v[i] << ' ';
			sum += v[i];
		}
	}
	time_t t_3 = clock();
	double tot_1 = double(t_2-t_1)/double(CLOCKS_PER_SEC);
	double tot_2 = double(t_3-t_2)/double(CLOCKS_PER_SEC);
	double avg_1 = tot_1/double(v.size());
	double avg_2 = tot_2/double(v.size());
	cout << endl << endl << "Elements: " << v.size() << endl;
	cout << "Time to generate: " << tot_1 << " Average: " << avg_1 << endl;
	cout << "Time to check: " << tot_2 << " Average: " << avg_2 << endl << "Sum: " << sum;
	pause();
}