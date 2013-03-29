#include "std_lib_facilities.h"

int main(){
	long croot = 2;
	long long numerator = 600851475143;
	while(numerator != 1){
		if((numerator % croot) == 0)
			numerator /= croot;
		else
			++croot;
	}
	cout << croot << ' ' << numerator << endl;
	keep_window_open();
}