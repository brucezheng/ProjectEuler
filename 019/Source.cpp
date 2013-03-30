/*
	Bruce Zheng
	Problem 019

	Determines number of sundays from Jan 01 1901 to Dec 31 2000. Strategy is that since
	Dec 31 1899 is a sunday, n mod 7 == 0 on a sunday, where n = days since 12/31/1899

	Additionally, I mad a loop to find the n values of all first days of months and check if
	they are sundays
*/

#include <iostream>

using namespace std;

// returns day of week; 0 = sunday; d = days since 12/31/1899
int dayOfWeek(int d) 
{ 
	return d%7;
}

// is year a leap year?
bool leapyear(int year) 
{ 
	if (year%4 == 0) {
		if (year%100 == 0) {
			if (year%400 == 0) {
				return true;
			}
			else return false;
		}
		else return true;
	}
	else return false;
}

int main() 
{
	int d = 366; // 1/1/1901
	int count = 0;
	// Check d for first day of month from 1/1/1901 to 12/1/1901
	for (int y = 1901; y <= 2000; ++y) {
		for (int m = 1; m <= 12; ++m) {
			if (dayOfWeek(d) == 0) ++count;
			if (m == 2) {
				if (leapyear(y)) d += 29;
				else d += 28;
			}
			else if (m == 4 || m == 6 || m == 9 || m == 11) {
				d += 30;
			}
			else d += 31;
		}
	}
	cout << count;
	char stall;
	cin >> stall;
}