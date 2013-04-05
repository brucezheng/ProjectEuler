/*
	Bruce Zheng
	Problem 029
	4/4/2013

	Basically, create a string with the factorization of each power, then insert into a map to
	remove duplicates. The size of the map is the number of distinct powers.
*/

#include <unordered_map>
#include <map>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void pause() 
{
	char ch;
	cin >> ch;
}

string factor(int num, int pow = 1)
{
	string result;
	int i = 2;
	while (i <= num) {
		if (num%i == 0) {
			result += '[';
			int k = 0;
			while (num%i == 0) {
				num /= i;
				++k;
			}
			result = result + to_string(i) + ',' + to_string((k*pow)) + ']';
		}
		++i;
	}
	return result;
}

int main()
{
	time_t s_u = clock();
	unordered_map<string,int> combos_u;
	for (int a = 2; a <= 100; ++a) {
		for (int b = 2; b <= 100; ++b) {
			combos_u.insert(pair<string,int>(factor(a,b),0));
		}
	}
	time_t e_u = clock();
	double t_u = double(e_u-s_u)/double(CLOCKS_PER_SEC);
	cout << "Unordered" << endl << "Number: " << combos_u.size() << endl
		 << "Time: " << t_u << endl << endl;
	
	/* Used to compare efficiency of maps
	time_t s_o = clock();
	map<string,int> combos_o;
	for (int a = 2; a <= 100; ++a) {
		for (int b = 2; b <= 100; ++b) {
			combos_o.insert(pair<string,int>(factor(a,b),0));
		}
	}
	time_t e_o = clock();
	double t_o = double(e_o-s_o)/double(CLOCKS_PER_SEC);
	cout << "Ordered" << endl << "Number: " << combos_o.size() << endl
		 << "Time: " << t_o << endl << endl;
	*/
	pause();
}