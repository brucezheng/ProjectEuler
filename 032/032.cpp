/*
	Bruce Zheng
	Problem 032
	4/5/2013

	If a*b=c and a,b,c are pandigital through 1-9, then c must be 4 digits and a,b must be either
	1 digit and 4 digits or 2 digits and 3 digits, respectively. Any other combination cannot 
	result in a total of 9 digits. Therefore I test each possible permutation of five digits for
	2 cases for each permutation. Testing if 3 numbers form a pandigital collection of digits just
	requires making an array of ints that keep track of counts of digits, and filling it;
*/

#include <iostream>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

bool is_pan(int x, int y, int z) 
{
	int d[10];
	for (int i = 0; i < 10; ++i)
		d[i] = 0;
	int i = 0;
	while (pow(10,i)<=x) {
		int k = int(x/pow(10,i))%10;
		++d[k];
		++i;
	}
	i = 0;
	while (pow(10,i)<=y) {
		int k = int(y/pow(10,i))%10;
		++d[k];
		++i;
	}
	i = 0;
	while (pow(10,i)<=z) {
		int k = int(z/pow(10,i))%10;
		++d[k];
		++i;
	}
	if (d[0] > 0) return false;
	for (int i = 1; i < 10; ++i) {
		if (d[i] != 1) return false;
	}
	return true;
}

int pairsum (int total, pair<int,int> data) {
	return total + data.second;
}

int main()
{
	map<int,int> pan;
	for (int a = 1; a < 10; ++a) {
		for (int b = 1; b < 10; ++b) {
		if (b != a) {
			for (int c = 1; c < 10; ++c) {
			if (c != b && c != a) {
				for (int d = 1; d < 10; ++d) {
				if ((d != c && d != b) && d != a) {
					for (int e = 1; e < 10; ++e) {
					if ((e != d && e != c) && (e != b && e != a)) {
						int temp_x = a*10+b;
						int temp_y = c*100+d*10+e;
						int temp_z = temp_x*temp_y;
						if (temp_z > 999) {
							if (is_pan(temp_x,temp_y,temp_z)) {
								cout << temp_x << ' ' << temp_y << ' ' << temp_z << endl;
								pan.insert(pair<int,int>(temp_z,temp_z));
							}
						}
						temp_x = a;
						temp_y = b*1000+c*100+d*10+e;
						temp_z = temp_x*temp_y;
						if (temp_z > 999) {
							if (is_pan(temp_x,temp_y,temp_z)) {
								cout << temp_x << ' ' << temp_y << ' ' << temp_z << endl;
								pan.insert(pair<int,int>(temp_z,temp_z));
							}
						}
					}
					}
				}
				}
			}
			}
		}
		}
	}
	int sum = accumulate(pan.begin(),pan.end(),0,pairsum);
	cout << endl << sum;
	pause();
}