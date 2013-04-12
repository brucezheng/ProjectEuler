/*
	Bruce Zheng
	Problem 044
	4/12/2013

	My attempts to find an algorithm to find the correct sequence of increasing differences proved
	fruitless, so this solution just brute forces all pentagonal numbers from P1 to P3000. Not 
	very elegant, but it works and is somewhat efficient.

	Determining if a pentagonal number relies on the fact that floor(sqrt(2n/3)) = k-1 for the kth
	pentagonal number.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

struct trip {
	int x;
	int y;
	int z;
	trip(int x_init, int y_init, int z_init) : x(x_init), y(y_init), z(z_init) { }
};

bool operator<(const trip& a, const trip& b) {
	return a.z < b.z;
}

void pause()
{
	char ch;
	cin >> ch;
}

bool ispent(int n)
{
	int k = int(sqrt(double(2*n)/3)) + 1;
	return n == (k)*(3*k-1)/2;
}

int pent(int n)
{
	return n*(3*n-1)/2;
}

int main()
{
	vector<int> v;
	vector<trip> t;
	time_t start = clock();
	for(int i = 1; i <= 3000; ++i) {
		v.push_back(pent(i));
	}
	for (int i = 1; i < 3000; ++i) {
		for (int j = 0; j < i; ++j) {
			if(ispent(v[i]-v[j])) {
				if(ispent(v[i]+v[j])) {
					t.push_back(trip(i+1,j+1,v[i]-v[j]));
				}
			}
		}
	}
	time_t end = clock();
	double duration = double(end-start)/double(CLOCKS_PER_SEC);
	sort(t.begin(),t.end());
	for (int i = 0; i < t.size(); ++i) {
		cout << '(' << t[i].x << ',' << t[i].y  << ',' << t[i].z << ") "; 
	}
	cout << endl << "Time taken: " << duration << endl;
	pause();
}