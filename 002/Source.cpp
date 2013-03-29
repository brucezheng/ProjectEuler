#include "std_lib_facilities.h"

int main(){
	long a = 1;
	long b = 2;
	long c;
	int iter = 2;
	while (b < 4000000){
		c = a + b;
		a = b;
		b = c;
		++iter;
	}
	long esum = 0;
	int mod = (iter % 3);
	if(mod == 2){
		esum = b + b + a;
	}
	if(mod == 0){
		esum = b + a;
	}
	if(mod == 1){
		esum = b;
	}
	--esum;
	esum /= 2;
	cout << esum << endl;
	keep_window_open();
}