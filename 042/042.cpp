/*
	Bruce Zheng
	Problem 042
	4/11/2013

	In addition to the program requirements, I also wrote all triangular words into a text document
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

// checks if n is a triangular number
bool istrig(int n)
{
	int k = sqrt(2*n);
	return int(k*k + k)/2 == n;
}

// gets the next word in the input stream, ignoring nonalpha characters
bool getword(istream& in, string& out)
{
	out.clear();
	char ch;
	if (in.get(ch)) {
		bool lastword = false;
		// sort out trash
		while (!isalpha(ch)) {
			// if we reach eof w/o any letters
			if (!in.get(ch)) return false;
		}
		while (isalpha(ch)) {
			out += ch;
			if (!in.get(ch)) {
				lastword = true;
				break;
			}
		}
		if (!lastword)
			in.unget();
	}
	else return false;
}

// returns "numeric value" of string
int to_int(string str) 
{
	int result = 0;
	for(int i = 0; i < str.length(); ++i) {
		if (isupper(str[i])) result += int(str[i]-'A')+1; 
		else if (islower(str[i])) result += int(str[i]-'a')+1;
	}
	return result;
}

int main()
{
	ifstream ifs("words.txt");
	vector<string> twords;
	string str;
	while (getword(ifs,str)) {
		if (istrig(to_int(str))) {
			twords.push_back(str);
		}
	}
	cout << twords.size();
	pause();
	ofstream ofs("trigwords.txt");
	ofs << "\"";
	for (int i = 0; i < twords.size()-1; ++i) {
		ofs << twords[i] << "\",\"";
	}
	ofs << twords[twords.size()-1] << "\"";
}