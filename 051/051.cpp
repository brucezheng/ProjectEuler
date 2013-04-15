#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

void pause()
{
	char ch;
	cin >> ch;
}

int length(int n)
{
	if (n >= 10000) {
		int i = 0;
		while (pow(10,i) <= n) ++i;
		return i;
	}
	else if (n >= 100) {
		if (n >= 1000) return 4;
		else return 3;
	}
	else {
		if (n >= 10) return 2;
		else return 1;
	}
}

vector<pair<int,int>> spaces(int sz, int n)
{
	vector<pair<int,int>> result;
	if (sz == 1) {
		if (n > -1) {
			pair<int,int> temp(n,0);
			result.push_back(temp);
		}
		else {
			pair<int,int> temp(0,1);
			result.push_back(temp);
		}
	}
	else {
		if (sz > length(n)) {
			vector<pair<int,int>>& a = spaces(sz-1,n);
			for(int i = 0; i < a.size(); ++i) {
				pair<int,int> temp(a[i]);
				temp.first *= 10;
				temp.second = temp.second*10 + 1;
				result.push_back(temp);
			}
		}
		if (n > -1) {
			int trunc;
			if (n < 10) trunc = -1;
			else trunc = n/10;
			vector<pair<int,int>>& b = spaces(sz-1,trunc);
			for(int i = 0; i < b.size(); ++i) {
				pair<int,int> temp(b[i]);
				temp.first = temp.first*10+(n%10);
				temp.second *= 10;
				result.push_back(temp);
			}
		}
	}
	return result;
}

/*
vector<vector<int>> spaces(int sz, const vector<int>& v)
{
	vector<vector<int>> result;
	if (sz == 1) {
		if (v.size() == 1) {
			result.push_back(v);
		}
		else {
			vector<int> temp;
			temp.push_back(-1);
			result.push_back(temp);
		}
	}
	else {
		if (sz > v.size()) {
			vector<vector<int>>& a = spaces(sz-1,v);
			for(int i = 0; i < a.size(); ++i) {
				vector<int> temp = a[i];
				temp.push_back(-1);
				result.push_back(temp);
			}
		}
		if (v.size() > 0) {
			vector<int> trunc;
			for (int i = 0; i < v.size()-1; ++i)
				trunc.push_back(v[i]);
			vector<vector<int>>& b = spaces(sz-1,trunc);
			for(int i = 0; i < b.size(); ++i) {
				vector<int> temp = b[i];
				temp.push_back(v[v.size()-1]);
				result.push_back(temp);
			}
		}
	}
	return result;
}
*/

int checkp (int x, int y, bool* p) {
	int count = 0;
	for (int i = 0; i < 10; ++i) {
		if (p[x+y*i]) ++ count;
	}
	return count;
}

int main()
{
	int n = 34;
	vector<pair<int,int>>& v = spaces(4,n);
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i].first << ' ' << v[i].second;
		cout << endl;
	}
	/*
	bool* p = new bool[100000];
	//time_t start = clock();
	vector<int> v;
	for (int i = 1; i < 4; ++i) {
		v.push_back(i);
	}
	//for (int i = 0; i < 1000; ++i) {
	vector<vector<int>>& a = spaces(4,v);
	//}
	//time_t end = clock();
	//double dur = double(end-start)/double(CLOCKS_PER_SEC);
	//cout << "TIME: " << dur << endl;
	for(int i = 0; i < a.size(); ++i) {
		int x = 0;
		int y = 0;
		int sz = a[i].size();
		for (int j = sz-1; j >= 0; --j) {
			if (a[i][j] != -1) {
				y += pow(10,sz-1-j)*(a[i][j]);
				//cout << a[i][j] << ' ';
			}
			else x += pow(10,sz-1-j)*1;
			//cout << "- ";
		}
		//cout << y << ' ' << x << endl;
		checkp (x,y,p);
		cout << endl;
	}
	*/
	pause();
}