/*
    Bruce Zheng
    Problem 099
    5/7/2013
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int log(double val, double pow) {
    return double(pow)*log(val);
}

int main()
{
    ifstream in;
    in.open("base_exp.txt");
    double val,pow,largest = 0;
    int bigindex = 1, i = 1;
    char ch;
    while(in) {
    	in >> val;
    	in.get(ch);
    	in >> pow;
	double temp = log(val,pow);
	if (temp > largest) {
	     bigindex = i;
	     largest = temp;
	}
	else if (temp == largest) cerr << "Whoops!";
	++i;
    }
    cout << bigindex << endl;
}
