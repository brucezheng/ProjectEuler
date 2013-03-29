#include "std_lib_facilities.h"
#include <numeric>
#include <time.h>


bool is_prime(long l){
	int root = sqrt(l);
	for(int i = 2; i <= root; ++i){
		if((l % i) == 0)
			return false;
	}
	return true;
}

bool is_prime_sieve(long l, const vector<long> &primes){
	int root = sqrt(l);
	int i = 0;
	while((i < primes.size()) & (primes[i] <= root)){
		if((l % primes[i]) == 0)
			return false;
		++i;
	}
	return true;
}

int main(){
	vector<long> primes;
	time_t start;
	start = time (NULL);
	primes.push_back(2);

	for(long i = 3; i < 2000000; ++i){
		if(is_prime(i))
			primes.push_back(i);
	}

	time_t end;
	end = time (NULL);
	
	cout << (end - start) << endl;
	
	long long sum = 0;
	for(vector<long>::iterator it = primes.begin(); it != primes.end(); ++it){
		sum += *it;
	}

	cout << sum <<endl;

	keep_window_open();
}