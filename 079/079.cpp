/*
	Bruce Zheng
	Problem 079
	4/18/2013

	I solved this problem through pen and paper; an algorithm could be made by constructing a Hasse
	diagram to solve the problem, however, and I might come back to this problem later.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

int main()
{
	map<string,string> log;
	ifstream in("keylog.txt");
	while (in) {
		string combo;
		in >> combo;
		log[combo] = combo;
	}
	map<string,string>::iterator it = log.begin();
	while (it != log.end()) {
		cout << it->second << ' ';
		++it;
	}
	pause();
}