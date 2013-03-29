#include "Collatz.h"
#include <iostream>

using namespace std;

int seq_length(int i) {
	long long l = i;
	int c = 1;
	while (l != 1 && l > 0) {
		++c;
		if (l & 1) l = 3*l + 1;
		else l = l/2;
	}
	return c;
}

int main() {
	cout << Collatz(13) << endl;
	
	int max = 1;
	int max_length = 1;
	for(int i = 1; i < 1000000; ++i) {
		int temp = seq_length(i);
		if (temp > max_length) {
			max = i;
			max_length = temp;
			cout << max << ' ' << max_length << endl;
		}
	}
	
	cout << max << ' ' << max_length << endl;

	char stall;
	cin >> stall;
	return 0;
}