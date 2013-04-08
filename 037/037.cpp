/*
	Bruce Zheng
	Problem 037
	4/7/2013

	The function genTP generates a vector of either rtl or ltr truncateable primes. It takes a set 
	of already truncateteable primes of the correct primes and checks for possible primes of one
	additional digit. In main, I call this recursively for both rtl and ltr and find the 
	intersection of those two vectors for each number of digits until I get 11 primes that work.
*/

#include <vector>
#include <iostream>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

bool isprime (int n) 
{
	for (int i = 2; i <= sqrt(n); ++i)
		if (n%i == 0) return false;
	return true;
}

const vector<int> base()
{
	vector<int> result;
	result.push_back(2);
	result.push_back(3);
	result.push_back(5);
	result.push_back(7);
	return result;
}

const vector<int> genTP(const vector<int>& seed, bool ltr = false)
{
	vector<int> result;
	int len = 0;
	if (seed.empty()) return result;
	if (ltr) {
		int len = 0;
		while (pow(10,len) <= seed[0])
			++len;
		for(int j = 1; j < 10; ++j) {
			for (int i = 0; i < seed.size(); ++i) {
				if (isprime(j*int(pow(10,len))+seed[i]))
					result.push_back(j*int(pow(10,len))+seed[i]);
			}
		}
	}
	else {
		for (int i = 0; i < seed.size(); ++i) {
			for (int j = 0; j < 5; ++j) { 
				if (isprime(10*seed[i]+(2*j+1)))
					result.push_back(10*seed[i]+(2*j+1));
			}
		}
	}

	return result;
}

const vector<int> intersection(const vector<int>& lhs, const vector<int>& rhs)
{
	vector<int> result;
	int i = 0;
	int j = 0;
	while (i < lhs.size() && j < rhs.size()) {
		if (lhs[i] == rhs[j]) {
			result.push_back(lhs[i]);
			++i;
			++j;
		}
		else if (lhs[i] < rhs[j]) ++i;
		else ++j;
	}
	return result;
}

int main()
{
	int count = 0;
	int sum = 0;
	vector<int> left = genTP(base(),true);
	vector<int> right = genTP(base(),false);
	while (count < 11) {
		vector<int> inter = intersection(left,right);
		for (int i = 0; i < inter.size(); ++i) {
			cout << inter[i] << ' ';
			sum += inter[i];
		}
		count += inter.size();
		if (left.empty() || right.empty()) break;
		left = genTP(left,true);
		right = genTP(right,false);
	}
	cout << endl << sum << endl;
	pause();
}