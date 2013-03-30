#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Triangle {
public:
	Triangle();
	Triangle(int h_init);
	vector<int> T;
	int& elem(int i, int j);
	vector<int> maxPaths(int i);
	int maxPath();
	int height() const { return h; };
private:
	int h;
	int trinum(int i);
};

Triangle::Triangle() : h(1) {
	vector<int> temp(1);
	T = temp;
}

Triangle::Triangle(int h_init) : h(h_init) {
	vector<int> temp(trinum(h_init));
	T = temp;
}

ostream& operator<<(ostream& out, Triangle& t) {
	for (int i = 0; i < t.height(); ++i) {
		for (int k = 0; k < t.height()-(i+1); ++k) {
			out << "  ";
		}
		for (int j = 0; j < i+1; ++j) {
			if (t.elem(i,j) < 10) out << "0";
			out << t.elem(i,j);
			if (j != i) out << "  ";
		}
		for (int k = 0; k < t.height()-(i+1); ++k) {
			out << "  ";
		}
		out << endl;
	}
	return out;
}

vector<int> Triangle::maxPaths(int i) {
	vector<int> row;
	if (i == 0) {
		row.push_back(elem(i,0));
	}
	else {
		const vector<int>& lastmax = maxPaths(i-1);
		for (int k = 0; k < i+1; ++k) {
			int max_k;
			if (k == 0) max_k = elem(i,0)+lastmax[0];
			else if (k == i) max_k = elem(i,k)+lastmax[k-1];
			else {
				if (lastmax[k-1] > lastmax[k]) max_k = elem(i,k)+lastmax[k-1];
				else max_k = elem(i,k)+lastmax[k];
			}
			row.push_back(max_k);
		}
	}
	return row;
}

int Triangle::maxPath() {
	int max = 0;
	const vector<int>& finalrow = maxPaths(h-1);
	for (int i = 0; i < h; ++i) {
		if (finalrow[i] > max) max = finalrow[i];
	}
	return max;
}

int& Triangle::elem(int i, int j) {
	return T[trinum(i)+j];
}

int Triangle::trinum(int i) {
	return ((i*i) + i) / 2;
}