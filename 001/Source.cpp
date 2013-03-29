#include "std_lib_facilities.h"
#include <numeric>

int main() {
	vector<int> valid;
	for(int i = 0; i < 1000; ++i)
		if((i % 3 == 0) || (i % 5 == 0))
			valid.push_back(i);
	int sum = accumulate(valid.begin(), valid.end(), 0);
	cout << sum << endl;
	keep_window_open();
	return 0;
}