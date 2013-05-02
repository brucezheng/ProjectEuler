/*
	Bruce Zheng
	4/26/2013
	Problem 059

	Basically we want to find the most common CT char for each char in the key. Those will most
	likely map to spaces.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <numeric>;

using namespace std;

void pause() 
{
	char ch;
	cin >> ch;
}

// find the most common int per individual key
int biggest(map<int,int>& m) 
{
	int max = 0;
	int big;
	map<int,int>::iterator i = m.begin();
	for(i; i != m.end(); ++i) {
		if (i->second > max) {
			big = i->first;
			max = i->second;
		}
	}
	return big;
}

int main()
{
	vector<map<int,int>> v(3);
	vector<int> msg;
	ifstream in("cipher1.txt");
	// compiling statistics of CT
	int i = 0;
	while(in) {
		int temp;
		in >> temp;
		// clear junk (commas)
		char ch;
		in >> ch;
		v[i][temp] += 1;
		i = (i+1)%3;
		msg.push_back(temp);
	}
	// determine what likely keys are
	vector<int> big(3);
	vector<int> key(3);
	for (int j = 0; j < big.size(); ++j) {
		big[j] = biggest(v[j]);
		key[j] = big[j]^int(' ');
	}
	i = 0;
	// decode and find sum!
	int sum = 0;
	for (int j = 0; j < msg.size(); ++j) {
		int k = msg[j]^key[i];
		sum += k;
		cout << char(k);
		i = (i+1)%3;
	}
	cout << endl;
	cout << sum << endl;
	pause();
}