#include "std_lib_facilities.h"

int main(){
	int a, b, c;
	c = 0;
	bool found = false;
	for(a = 1; a < 1000; ++a){
		for(b = a; b < 1000; ++b){
			int temp = 1000 - (a + b);
			if(((a * a) + (b * b)) == (temp * temp)){
				found = true;
				c = temp;
				break;
			}
		}
		if(found)
			break;
	}
	cout << a << ' ' << b << ' ' << c << endl;
	cout << (a * b * c) << endl;
	keep_window_open();
}