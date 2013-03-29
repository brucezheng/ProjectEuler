#include <vector>
#include <string>

using namespace std;

class Collatz: public vector<long> {
public:
	Collatz();
	Collatz(long i);
	const int seed() const { return s; }
private:
	long s;
};

Collatz::Collatz() 
{
	s = 1;
	push_back(1);
}

Collatz::Collatz(long i)
{
	s = i;
	long n = i;
	while (n != 1) {
		push_back(n);
		if (n%2 == 0) n = n/2;
		else n = 3*n+1;
	}
	push_back(1);
}

ostream& operator<<(ostream& out, const Collatz& seq)
{
	out << seq.seed() << " {";
	for (int i = 0; i < seq.size(); ++i) {
		out << seq[i];
		if (i != seq.size()-1) out << ", ";
	}
	out << '}';
	return out;
}