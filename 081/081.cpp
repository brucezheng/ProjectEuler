/*
	Bruce Zheng
	5/6/2013
	Problem 081
	
	Simple shortest path tree type solution. Djikstra's algorithm.
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

typedef vector<vector<int>> matrix_t;
typedef vector<int> row_t;

void pause()
{
	char ch;
	cin >> ch;
}

ostream& operator<<(ostream& out, matrix_t m) {
	for(int i = 0; i < m.size(); ++i) {
		for (int j = 0; j < m[i].size(); ++j)
			out << m[i][j] << ' ';
		out << endl;
	}
	return out;
}

void init_matrix(matrix_t& m, int height, int width)
{
	m.clear();
	for(int i = 0; i < height; ++i) {
		row_t temp(width);
		m.push_back(temp);
	}
}

void update_path(matrix_t& m, int i, int j)
{
	if (i < 0 || j < 0) cerr << "Invalid index values (matrix update_path)";
	if (i > 0) {
		if (j > 0) m[i][j] += min(m[i-1][j],m[i][j-1]);
		else m[i][j] += m[i-1][j];
	}
	else if (j > 0) m[i][j] += m[i][j-1];
}

void ssp_traverse(matrix_t& m)
{
	int height = m.size(), width = m[0].size();
	int i = 0, j = 0;
	bool done = false;
	while (!done) {
		update_path(m,i,j);
		if (j == width-1) {
			if (i == height-1) done = true;
			else {
				j = i+1;
				i = height-1;
			}
		}
		else if (i == 0) {
			i = j+1;
			j = 0;
		}
		else {
			--i;
			++j;
		}
	}
}

void main()
{
	srand(time(NULL));
	matrix_t m;
	init_matrix(m,80,80);
	ifstream in;
	in.open("matrix.txt");
	for (int i = 0; i < 80; ++i) {
		for (int j = 0; j < 80; ++j) {
			int temp;
			char trash;
			in >> temp;
			in.get(trash);
			if (trash != ',') in.unget();
			m[i][j] = temp;
		}
	}
	ssp_traverse(m);
	cout << m[79][79] << endl;
	pause();
}
