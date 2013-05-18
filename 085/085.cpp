/*
	Bruce Zheng
	Problem 085
	5/18/2013

	The number of rectangles in an nxm rectangle is the nth triangular number times the mth
	triangular number
*/

#include <iostream>
#include <ctime>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

int rect(int n, int m) {
	return ((n*n+n)/2)*((m*m+m)/2);
}

int main()
{
	time_t start = clock();
	const int target = 2000000;
	// by quick testing, 1x2000 and 53x53 produce values near 2x10^6
	int lastlen = 2001;
	int diff = target;
	pair<int,int> dims(0,0);
	for(int i = 1; i < 54; ++i) {
		int j = lastlen;
		int last = 0, curr = 0;
		// curr = rect(i,j), last = rect(i,j+1)
		while(true) {
			last = curr;
			curr = rect(i,j);
			if (curr < target) break;
			--j;
		}
		if (target-curr < diff) {
			diff = target-curr;
			dims.first = i;
			dims.second = j;
		}
		if (last-target < diff) {
			diff = last-target;
			dims.first = i;
			dims.second = j+1;
		}
		lastlen = j;
	}
	cout << '(' << dims.first << ',' << dims.second << ")" << endl;
	cout << "DIFF: " << diff << endl << "AREA: " << dims.first*dims.second << endl;
	time_t end = clock();
	cout << "TIME: " << double(end-start)/double(CLOCKS_PER_SEC);
	pause();
}