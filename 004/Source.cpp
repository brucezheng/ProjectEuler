#include "std_lib_facilities.h"

bool palin(int i){
	ostringstream o;
	o << i;
	string forward = o.str();
	string backward = string (forward.rbegin(), forward.rend());
	return forward == backward;
}

int main(){
	int largest = 0;
	int current = 0;
	for(int i = 0; i < 1000; ++i){
		for(int j = 0; j < 1000; ++j){
			current = i * j;
			if((current > largest) & palin(current))
				largest = current;
		}
	}
	cout << largest << endl;
	keep_window_open();
}