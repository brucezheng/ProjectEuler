#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename Obj>
struct ListPair {
	list<Obj> first;
	list<Obj> second;
	ListPair() : first(), second() { }
	ListPair(list<Obj> first_init, list<Obj> second_init) : first(first_init), second(second_init) { }
};

void pause() 
{
	char ch;
	cin >> ch;
}

BigInt pow(BigInt base, BigInt exp) {
	BigInt result(1);
	for (BigInt i(0); i < exp; ++i) {
		result *= base;
	}
}

ListPair<int> decimal(int den) 
{
	list<int> S;
	list<int> R;
	int rem = 10;
	int div = den;
	bool done = false;
	while (!done) {
		S = R;
		R.clear();
		// add next digit
		S.push_back(rem/div);
		rem = (rem - div*int(rem/div)) * 10;
		int total_size = S.size();
		cout << total_size << ' ';
		if (total_size > 50) pause();
		// for all combinations of recurring/non recurring digits
		for (int i = 0; i <= total_size; ++i) {
			long S_num = 0;
			long S_den = pow(10,S.size());
			// generate fractions for repeating part and static part
			int s_ind = 0;
			for (list<int>::iterator s_iter = S.begin(); s_iter != S.end(); ++s_iter) {
				S_num += long(*s_iter)*long(pow(10,S.size()-(s_ind+1)));
				++s_ind;
			}
			long R_num = 0;
			long R_den = 0;

			int r_ind = 0;
			for (list<int>::iterator r_iter = R.begin(); r_iter != R.end(); ++r_iter) {
				R_num += long(*r_iter)*long(pow(10,R.size()-(r_ind+1)));
				++r_ind;
			}
			for (int j = 0; j < R.size(); ++j) {
				R_den += 9*pow(10,j);
			}
			R_den *= pow(10,S.size());
			if (R_den == 0) R_den = 1;
			// check if these fractions are equal
			if (S_num*R_den+R_num*S_den != 0) {
				if ((S_den*R_den)/(S_num*R_den+R_num*S_den) == den && (S_den*R_den)%(S_num*R_den+R_num*S_den) == 0) {
					done = true;
					break;
				} 
			}
			list<int>::iterator s_iter = S.end();
			if (s_iter != S.begin()) {
				--s_iter;
				R.push_front(*s_iter);
				S.erase(s_iter);
			}
		}
	}
	ListPair<int> pr(S,R);
	return pr;
}

int main ()
{
	ListPair<int> lp(decimal(19));
	//for (int i = 2; i <= 100; ++i) {
	//	cout << i << ' ';
	//	ListPair<int> temp(decimal(i));
	//	if (temp.second.size() > lp.second.size()) 
	//		lp = temp;
	//}
	cout << "0.";
	for (list<int>::iterator i = lp.first.begin(); i != lp.first.end(); ++i) {
		cout << *i;
	}
	if (lp.second.size() > 0) {
		cout << '[';
		for (list<int>::iterator i = lp.second.begin(); i != lp.second.end(); ++i) {
			cout << *i;
		}
		cout << ']';
	}
	pause();
}