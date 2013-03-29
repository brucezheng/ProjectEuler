#include <iostream>
#include <sstream>  
#include <fstream>
#include <string>

#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;
using namespace std;

Matrix<int,2> make(string filename) {
	ifstream f(filename);
	//find width and height of matrix
	int width = 0;
	int height = 0;
	if (f) {
		++height;
		string row;
		getline(f,row);
		istringstream s(row);
		while (s) {
			int elem;
			s >> elem;
			if (s) ++width;
		}
	}
	while (f) {
		string row;
		getline(f,row);
		if (f) ++height;
	}

	//return to top
	f.clear();
	f.seekg(0, ios::beg);

	//fill in matrix
	Matrix<int,2> m(height,width);
	for (int i = 0; i < height; ++i) {
		string row;
		getline(f,row);
		istringstream s(row);
		for (int j = 0; j < width; ++j) {
			int elem;
			s >> elem;
			m(i,j) = elem;
		}
	}

	return m;
}

int maxProd(Matrix<int,2>& m, int i, int j) {
	int max = 0;
	if (j+3 < m.dim2()) {
		int rowProd = m(i,j) * m(i,j+1) * m(i,j+2) * m(i,j+3);
		if (rowProd > max) max = rowProd;
	}
	if (i+3 < m.dim1()) {
		int colProd = m(i,j) * m(i+1,j) * m(i+2,j) * m(i+3,j);
		if (colProd > max) max = colProd;
	}
	if (j+3 < m.dim2() && i+3 < m.dim1()) {
		int DDProd = m(i,j) * m(i+1,j+1) * m(i+2,j+2) * m(i+3,j+3);
		if (DDProd > max) max = DDProd;
	}
	if (j+3 < m.dim2() && i-3 >= 0) {
		int UDProd = m(i,j) * m(i-1,j+1) * m(i-2,j+2) * m(i-3,j+3);
		if (UDProd > max) max = UDProd;
	}
	return max;
}

int maxProd(Matrix<int,2>& m) {
	int max = 0;
	for (int i = 0; i < m.dim2(); ++i) {
		for (int j = 0; j < m.dim1(); ++j) {
			int temp = maxProd(m,i,j);
			if (temp > max) max = temp;
		}
	}
	return max;
}

int main() {
	Matrix<int,2>& m = make("matrix.txt");
	int max = maxProd(m);
	cout << max;
	char stall;
	cin >> stall;
}