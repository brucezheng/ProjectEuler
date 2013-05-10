/*
	Bruce Zheng
	Problem 076
	5/10/2013

	Oh my god this solution is so elegant*. Basically we generate p(n) inductively, like so: we see
	that there are going to be summations where the biggest integer in the sum (call it k) is n, 
	n-1, ..., etc. For aribtrary k, the number of partitions will be at most p(n-k). However, it 
	isn't necessarily equal to p(n-k), we need to eliminate the summations that have a larger
	largest integer than k. To be able to count only those summations, we keep track of p(n) by
	storing an int vector in which p(n)[i] = number of summations with greatest integer i. The
	helper function summations lets us easily determine sum i = 1 to k of p(n-k). Each p(n) vector
	has a element at index 0; this doesn't mean anything theoretically, I just added it to keep
	indicies easy to deal with. Note that to get the actual answer we must subtract 1 from p(n),
	since the problem asks for 

	*: Okay, maybe not as elegant as the actual mathematical formula for partitions, but WHATEVER
	BRO, GET OFF MY CASE IM JUST AN UNDERGRAD JEEZ
*/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

typedef vector<int> part;

void pause()
{
	char ch;
	cin >> ch;
}

int summation(part& p, int i = -1) {
	int result = 0;
	if (i == -1 || i > p.size()-1) i = p.size()-1;
	for (int j = 0; j <= i; ++j) {
		result += p[j];
	}
	return result;
}

int main()
{
	time_t start = clock();
	// seeding our p function
	vector<part> sums;
	part seed;
	seed.push_back(0);
	sums.push_back(seed);
	seed.push_back(1);
	sums.push_back(seed);
	// generating summations
	for (int i = 2; i < 101; ++i) {
		// temp = p(n)
		part temp; 
		temp.push_back(0);
		for (int j = 1; j < i; ++j) {
			// p(n-j)[1] + ... + p(n-j)[j]
			temp.push_back(summation(sums[i-j],j)); 
		}
		// p(n)[n] = 1, obviously
		temp.push_back(1); 
		sums.push_back(temp);
	}
	cout << summation(sums[100]) << endl;
	time_t end = clock();
	cout << "TIME: " << double(end-start)/double(CLOCKS_PER_SEC) << endl;
	pause();
}

/* inefficient algorithm :(

typedef vector<string> partit;

ostream& operator <<(ostream& out, partit p) {
	for (int i = 0; i < p.size(); ++i)
		cout << p[i] << ' ';
	return out;
}

int main()
{ 
	time_t start = clock();
	// initializing our partitons; p(0) = 0, p(1) = 1
	vector<partit> sums;
	partit seed;
	sums.push_back(seed);
	seed.push_back("1");
	sums.push_back(seed);
	for (int i = 2; i < 30; ++i) {
		partit temp;
		temp.push_back(to_string(i));
		for (int j = i-1; j > 0; --j) {
			for (int k = 0; k < sums[i-j].size(); ++k) {
				string cand = sums[i-j][k];
				if (int(cand[0])-48 <= j) {
					temp.push_back(to_string(j)+"+"+cand); 
				}
			}
		}
		sums.push_back(temp);
	}
	time_t end = clock();
	//cout << sums[100].size() << endl;
	cout << "TIME: " << double(end-start)/double(CLOCKS_PER_SEC) << endl;
}
*/