/*
	Bruce Zheng
	Problem 074
	5/18/2013

	Very slow implementation, basically bruteforce compute the factorial sums and check for
	collisions using a hash map.
*/

#include <iostream>
#include <ctime>
#include <unordered_map>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

int dfact(int i) {
	if (i < 5) {
		if (i < 2) {
			return 1;
		}
		else {
			if (i < 4) {
				if (i < 3) return 2;
				else return 6;
			}
			else return 24;
		}
	}
	else {
		if (i < 7) {
			if (i < 6) return 120;
			else return 720;
		}
		else {
			if (i < 9) {
				if (i < 8) return 5040;
				else return 40320;
			}
			else return 362880;
		}
	}
}

int dfactsum(int i) {
	int k = i;
	int result = 0;
	while (k > 0) {
		result += dfact(k%10);
		k /= 10;
	}
	return result;
}

int main() 
{
	time_t start = clock();
	int ct = 0;
	for (int i = 0; i < 1000000; ++i) {
		if (i % 10000 == 0) cout << '#';
		unordered_map<int,int> coll;
		int k = i;
		int j = 1;
		++coll[k];
		for (j; j < 61; ++j) {
			k = dfactsum(k);
			++coll[k];
			if (coll[k] > 1) break;
		}
		if (j == 60) ++ct;
	}
	cout << endl << ct << endl;
	time_t end = clock();
	cout << "TIME: " << double(end-start)/double(CLOCKS_PER_SEC) << endl;
	pause();
}