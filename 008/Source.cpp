#include "std_lib_facilities.h"

int main(){
	ifstream is;
	is.open ("number.txt");
	int product, max;
	int a, b, c, d, e;
	char temp;

	is.get(temp); a = temp - '0';
	is.get(temp); b = temp - '0';
	is.get(temp); c = temp - '0';
	is.get(temp); d = temp - '0';
	is.get(temp); e = temp - '0';

	product = a * b * c * d * e;
	max = product;
	cout << product << endl;

	while(is.get(temp)){
		a = b; b = c; c = d; d = e;
		e = temp - '0';
		product = (a * b * c * d * e);
		if(product > max)
			max = product;
		cout << product << endl;
	}

	cout << max << endl;
	keep_window_open();
}