/*
	Bruce Zheng
	Problem 039
	4/9/13

	Defined a recursive function to find all primitive pythagorean triples that add to less than
	one thousand by using Breggen's method of matrix transformations of pythagorean triples. Then,
	compute all possible sums of integer multiples of these triples and find the largest sum, 
	using an array. A simple triple class was also used to facilitate this algorithm.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class triple {
public:
	int first;
	int second;
	int third;
	int sum() const { return first + second + third; }
	triple() : first(), second(), third() { }
	triple(int a,int b,int c) : first(a), second(b), third(c) { }
};

void pause() 
{
	char ch;
	cin >> ch;
}

bool comp(const triple& a, const triple& b) 
{
	if (a.third == b.third)
		return min(a.first,a.second) < min(b.first,b.second);
	else return a.third < b.third;
}

void genpyth(vector<triple>& v, triple t = triple(3,4,5)) 
{
	// using matrix transformations
	triple x;
	x.first = t.first+2*t.second+2*t.third;
	x.second = 2*t.first+t.second+2*t.third;
	x.third = 2*t.first+2*t.second+3*t.third;
	triple y(x.first-4*t.second,x.second-2*t.second,x.third-4*t.second);
	triple z(x.first-2*t.first,x.second-4*t.first,x.third-4*t.first);
	
	if (x.sum() <= 1000) {
		v.push_back(x);
		genpyth(v,x);
	}
	if (y.sum() <= 1000) {
		v.push_back(y);
		genpyth(v,y);
	}
	if (z.sum() <= 1000) {
		v.push_back(z);
		genpyth(v,z);
	}
}

int main()
{
	// generate all primitive triples with sum < 1000
	vector<triple> v;
	triple seed(3,4,5);
	v.push_back(seed);
	genpyth(v);
	// sort and print these triples (not needed, just nice to see)
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); ++i) {
		cout << left 
			 << setw(4) << min(v[i].first,v[i].second)
			 << setw(4) << max(v[i].first,v[i].second) 
			 << setw(4) << v[i].third 
			 << endl;
	}
	// find the perimeter value with the most pythagorean triples
	int counts[1001] = {};
	for (int i = 0; i < v.size(); ++i) {
		int k = 1;
		while (k*v[i].sum() <= 1000) {
			++counts[k*v[i].sum()];
			++k;
		}
	}
	int max = 0;
	int perim = 0;
	for (int i = 0; i < 1000; ++i) {
		if (counts[i] > max) {
			max = counts[i];
			perim = i;
		}
	}
	cout << endl << perim << ' ' << max << endl;
	pause();
}
