/*
	Bruce Zheng
	Problem 024
	3/31/2013

	Originally I tried a brute force method that took well over a minute. My final solution used
	the fact that for all permutations of n digits, the first (n-1)! permutations start with the 
	first digit, the next (n-1)! permutations start with the second digit, et cetera. Of the
	(n-1)! permutations that start with the first digit, the first (n-2)! permutations start with
	the first unchosen digit, etc, and this process continues for all digits. Thus, we can 
	determine any ith permutation in O(n) time for n digits by using this fact.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// pause dat ish
void pause ()
{
	char ch;
	cin >> ch;
}


// n!
int fact(int n) 
{
	int result = 1; 
	for (int i = n; i > 0; --i) {
		result *= i;
	}
	return result;
}


// brute force method; too inefficient
void permute(vector<string>& targ, vector<int> digits, string seed = "") 
{
	if (digits.size() == 0) 
		targ.push_back(seed);
	else {
		for (int i = 0; i < digits.size(); ++i) {
			vector<int> temp;
			for (int j = 0; j < digits.size(); ++j) {
				if (j != i) 
					temp.push_back(digits[j]);
			}
			permute(targ, temp, seed+char('0'+digits[i]));
		}
	}
}

// do things
int main () 
{
	vector<int> d;
	for (int i = 0; i < 10; ++i) {
		d.push_back(i);
	}
	
	// quick method, O(n)
	int index = 999999;
	string perm;
	for(int i = 9; i >= 0; --i) {
		int k = index / fact(i);
		perm += char(d[k]+'0');
		index -= k*fact(i);
		d.erase(d.begin()+k);
	}
	
	cout << perm;

	pause();
}