/*
	Bruce Zheng
	Problem 062
	5/10/2013

	Signature computes the "signature" of a permutation, meaning all permutations of a number have
	the same value of that function, which counts digits. In the main code, I check all cubes of
	increasing digit length and store cubes by their signature in a map, counting the number of
	cubes each permutation may have.
*/

#include <map>
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

vector<int> sig(long long n) {
	vector<int> result(10);
	while (n > 0) {
		++result[int(n%10)];
		n /= 10;
	}
	return result;
}

ostream& operator<<(ostream& out, vector<int>& v) {
	for (int i = 0; i < v.size(); ++i) {
		out << v[i] << ' ';
	}
	return out;
}

int main()
{
	time_t start = clock();
	const int num_perms = 5;
	bool done = false;
	int power = 1;
	while (!done) {
		int low = ceil(pow(pow(10,power-1),double(1)/double(3)));
		int high = floor(pow(pow(10,power),double(1)/double(3)));
		map<vector<int>, vector<int> > m;
		for (int i = low; i <= high; ++i) {
			m[sig(long long(i)*long long(i)*long long(i))].push_back(i);
		}
		map<vector<int>,vector<int>>::iterator it = m.begin();
		while (it != m.end()) {
			if (it->second.size() == num_perms) {
				cout << it->second << endl;
				done = true;
			}
			++it;
		}
		++power;
	}
	time_t end = clock();
	cout << "TIME: " << double(end-start)/double(CLOCKS_PER_SEC) << endl;\
	pause();
}