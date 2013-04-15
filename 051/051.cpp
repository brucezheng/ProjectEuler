/*
	Bruce Zheng
	Problem 051
	4/15/2013

	There are three main components to this program. First, spaces creates a set of numbers with
	replacement slots in the form of a pair of numbers. The first number in the pair represents 
	the part of the number which is not replaced by digits, whereas the second number does. Checkp
	checks these two numbers to see how many digits result in a prime. Main produces an array to 
	check primes and also produces all combinations of possible number replacement pairs to check.
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

// number of digits in n
int length(int n)
{
	if (n >= 10000) {
		int i = 0;
		while (pow(10,i) <= n) ++i;
		return i;
	}
	else if (n >= 100) {
		if (n >= 1000) return 4;
		else return 3;
	}
	else {
		if (n >= 10) return 2;
		else return 1;
	}
}

// first = not digit replacing; second = digit replacing
vector<pair<int,int>> spaces(int sz, int n)
{
	vector<pair<int,int>> result;
	if (sz == 1) {
		if (n > -1) {
			pair<int,int> temp(n,0);
			result.push_back(temp);
		}
		else {
			pair<int,int> temp(0,1);
			result.push_back(temp);
		}
	}
	else {
		if (sz > length(n)) {
			vector<pair<int,int>>& a = spaces(sz-1,n);
			for(int i = 0; i < a.size(); ++i) {
				pair<int,int> temp(a[i]);
				temp.first *= 10;
				temp.second = temp.second*10 + 1;
				result.push_back(temp);
			}
		}
		if (n > -1) {
			int trunc;
			if (n < 10) trunc = -1;
			else trunc = n/10;
			vector<pair<int,int>>& b = spaces(sz-1,trunc);
			for(int i = 0; i < b.size(); ++i) {
				pair<int,int> temp(b[i]);
				temp.first = temp.first*10+(n%10);
				temp.second *= 10;
				result.push_back(temp);
			}
		}
	}
	return result;
}

// x = not repeating; y = repeating
int checkp (int x, int y, bool* p) {
	int count = 0;
	if (y == 0) {
		if (p[x]) ++count;
	}
	else {
		if (length(x) >= length(y)) {
			if (p[x]) ++count;
		}
		for (int i = 1; i < 10; ++i) {
			if (p[x+y*i]) ++count;
		}
	}
	return count;
}

int main()
{
	time_t start = clock();
	const int size = 1000001;
	// true = prime
	bool *p = new bool[size];
	// initializing stack
	p[0] = false;
	p[1] = false;
	for (int i = 2; i < size; ++i)
		p[i] = true;
	// getting prime numbers
	for (int i = 2; i < size; ++i)
		if (p[i])
			for (int j = 2; j <= (size-1)/i; ++j) 
				p[j*i] = false;
	// do stuff
	bool done = false;
	int i = 1;
	while (!done && i < 7) {
		for (int j = 1; j < pow(10,i); ++j) {
			if (length(j) != i) {
				vector<pair<int,int>>& v = spaces(i,j);
				for (int k = 0; k < v.size(); ++k) {
					if (checkp(v[k].first,v[k].second,p) >= 8) {
						cout << v[k].first << ' ' << v[k].second << endl;
						done = true;
					}
				}
			}
		}
		++i;
	}
	time_t end = clock();
	double dur = double(end-start)/double(CLOCKS_PER_SEC);
	cout << "TIME: " << dur << endl;
	pause();
}