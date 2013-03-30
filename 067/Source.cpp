#include <iostream>
#include <fstream>
#include <vector>
#include "TrianglePath.h"

using namespace std;

int trinum(int i) {
	return ((i*i) + i) / 2;
}

int main() {
	vector<int> file;
	ifstream ifs("tri.txt");
	int i;
	while (ifs >> i) file.push_back(i);
	
	int h = 0;
	while (trinum(h) <+ file.size()) ++h;

	Triangle t(h);
	for(int i = 0; i < file.size(); ++i) {
		t.T[i] = file[i];
	}

	cout << t << endl;
	cout << t.maxPath();
	char stall;
	cin >> stall;
}