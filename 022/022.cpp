/*
	Bruce Zheng
	Problem 022
	3/30/2013

	Straightforward implementation, convert text document into vector of strings and stl sort vector.
	Summation algorithm very simple.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// avoid quitting terminal in windows
void pause() 
{
	char stall;
	cin >> stall;
}

// letting a = 1, b = 2, etc, our letter sum is the sum of all letters in a string
int letterSum(string str)
{
	int result = 0;
	for (int i = 0; i < str.length(); ++i) {
		char ch = str[i];
		if (islower(ch))
			result += int(ch-'a'+1);
		else if (isupper(ch))
			result += int(ch-'A'+1);
	}
	return result;
}

int main()
{
	vector<string> names;
	ifstream ifs("names.txt");
	char ch;
	// constructing and sorting our sequence of names
	while (ifs.get(ch)) {
		if (ch == '\"') {
			string str;
			ifs.get(ch);
			while (ch != '\"') {
				str += ch;
				ifs.get(ch);
			}
			names.push_back(str);
		}
	}
	sort(names.begin(),names.end());

	// summing up scores of our names
	long total = 0;
	for (int i = 0; i < names.size(); ++i) {
		total += long((i+1)*letterSum(names[i]));
	}
	cout << total << endl;
	
	pause();
}
