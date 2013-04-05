/*
	Bruce Zheng
	Problem 026
	4/4/2013

	This problem is MUCH MUCH slower than a near optimal way of doing it, which is checking the
	smallest k such that 10^k - 1 is divisible by the denominator n. This method very painfully
	checks the actual decimal using strings. It's about a 10 minute runtime, but I don't really
	feel like implementing a better method of solving it.
*/

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <ctime>

#include "BigInt.h"

using namespace std;

struct StringPair {
	StringPair(string first_init, string second_init) : first(first_init), second(second_init) { }
	string first;
	string second;
};

void pause() 
{
	char ch;
	cin >> ch;
}

bool isprime(int i) 
{
	for (int j = 2; j <= sqrt(i); ++j) {
		if (i%j == 0) return false;
	}
	return true;
}

// hard check actually adding, mega slow
bool check(const string& sta, const string& rep, int den) 
{
	BigInt s_num(sta);
	BigInt r_num(rep);
	string s_dstr = "1";
	string r_dstr;
	for (int i = 0; i < rep.size(); ++i) {
		r_dstr += '9';
	}
	for (int i = 0; i < sta.size(); ++i) {
		s_dstr += '0';
		r_dstr += '0';
	}
	BigInt s_den(s_dstr);
	BigInt r_den(r_dstr);
	if (r_den == BigInt(0)) r_den = BigInt(1);
	//cout << s_num << '/' << s_den << " + ";
	//cout << r_num << '/' << r_den << endl;
	//pause();
	BigInt big_den(s_den*r_den);
	BigInt big_num(s_den*r_num+s_num*r_den);
	if (big_num == BigInt(0)) return false;
	if (big_den/big_num == BigInt(den) & big_den%big_num == BigInt(0))
		return true;
	return false;
}

// soft check brute force
StringPair decimal(int den) 
{
	string digits;
	string scan;
	string sta;
	string rep;
	int rem = 10;
	int div = den;
	bool done = false;

	/*while (!done) {
		deci += char(rem/div + '0');
		rem = (rem-div*int(rem/div))*10;
		bool checklarge = true;
		for (int i = 0; i < 10; ++i) {
			if (3*(i+1) > deci.size) {
				break;
				checklarge = false;
			}
		}
		if (checklarge) {
			for (int i = 0; i < deci.size()-scan.size(); ++i) {
				if(scan.substr(scan.size()-deci.size()-i-1).compare(deci) == 0) {
					done = true;
					
				}
			}
		}
	}*/
	while (!done) {
		// add next digit
		digits += char(rem/div + '0');
		rem = (rem-div*int(rem/div))*10;
		for (int i = 1; i <= digits.size()/2; ++i) {
			string& a = digits.substr(0,digits.size()-2*i);
			string& b = digits.substr(digits.size()-2*i,i);
			string& c = digits.substr(digits.size()-i);
			if(b.compare(c) == 0) {
				int soft = true;
				if (b.size() < 20) {
					int temp_rem = rem;
					string d;
					int i = 20/b.size()+1;
					for (int j = 0; j < i; ++j) {
						d.clear();
						for(int i = 0; i < c.size(); ++i) {
							d += char(temp_rem/div + '0');
							temp_rem = (temp_rem-div*int(temp_rem/div))*10;
						}
						if (b.compare(d) != 0) {
							soft = false;
							break;
						}
					}
				}
				//cout << '[' << b << ' ' << c << ' ' << d << ']';
				//pause();
				if(soft) {
					sta = a;
					rep = b;
					done = true;
					break;
				}
			}
		}
	}
	if (rep.compare("0") == 0) rep = "";
	StringPair p(sta,rep);
	return p;
}

int main ()
{
	int max_den = 1;
	time_t start = clock();
	for (int i = 3; i <= 1000; ++i) {
		if (isprime(i)) {	
			max_den = i;
		}
	}
	StringPair biggest(decimal(max_den));
	int max = biggest.second.size();
	/* brute force: 10min
	for (int i = 3; i <= 1000; ++i) {
		cout << i << ' ';
		p = decimal(i);
		if(p.second.size() > max) {
			max_den = i;
		biggest = p;
			max = p.second.size();
		}
	}
	*/
	time_t end = clock();
	cout << "Time: " << double(double(end - start)/double(CLOCKS_PER_SEC)) << endl;
	cout << "Repeating Digits: " << biggest.second.size() << endl;
	cout << "Fraction: " << "1/" << max_den << endl;
	cout << "Decimal: ";
	cout << "0." << biggest.first;
	if (biggest.second.size() > 0) {
		cout << '[' << biggest.second << ']';
	}
	cout << ' ';

	pause();
}