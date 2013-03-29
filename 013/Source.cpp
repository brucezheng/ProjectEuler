#include "BigInt.h"
#include <fstream>

using namespace std;

int main() 
{
	ifstream ifs("numbers.txt");
	BigInt sum;
	while (ifs) {
		string str;
		getline(ifs,str);
		
		if (ifs) {
			cout << BigInt(str) << endl;
			sum += BigInt(str);
		}
	}
	cout << endl << (sum) << endl;
	char stall;
	cin >> stall;
}