#include "std_lib_facilities.h"

int cons_sqrsum(int i){
	int sum = ((i) * (i + 1) * (2*i + 1)) / 6;
	return sum;
}

int cons_sum(int i){
	int sum = (i) * (i + 1) / 2;
	return sum;
}

int main(){
	int difference = abs(cons_sqrsum(100) - (cons_sum(100) * cons_sum(100)));
	cout << difference << endl;
	keep_window_open();
}