#include "std_lib_facilities.h"

int main(){
	vector<int> primes;
	primes.push_back(2);
	int i = 3;
	bool divisible = false;

	while(primes.size() < 10001){
		divisible = false;
		for(int j = 0; j < primes.size(); ++j){
			if((i % primes[j]) == 0){
				divisible = true;
				break;
			}
		}
		if(!divisible){
			primes.push_back(i);
		}
		++i;
	}

	//for(int k = 0; k < primes.size(); ++k){
	//	cout << primes[k] << ' ';
	//}
	cout << primes[primes.size() - 1];
	cout << endl;
	keep_window_open();
}