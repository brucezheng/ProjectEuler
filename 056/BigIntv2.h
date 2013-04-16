/*
	Bruce Zheng
	BigInt v2
	
	4/15/2013: Implemented constructors, addition/multiplication, comparison operators. Only
	handles unsigned BigInts at the moment!
*/

#include <iostream>
#include <vector>

class BigInt {
public:
	// constructors
	BigInt();
	BigInt(string s);
	BigInt(int i);
	// other
	bool positive;
	string str() const;
	// arithmetic operators
	BigInt operator+(const BigInt& other) const;
	BigInt operator*(const BigInt& other) const;
	// comparison operators
	bool operator==(const BigInt& other) const;
	bool operator!=(const BigInt& other) const;
	bool operator>(const BigInt& other) const;
	bool operator<(const BigInt& other) const;
	bool operator>=(const BigInt& other) const;
	bool operator<=(const BigInt& other) const;
private:
	vector<int> I
	int absComp(const BigInt& l, const BigInt& r) const;
	bool eitherZero(const BigInt& l, const BigInt& r) const;
	bool bothZero(const BigInt& l, const BigInt& r) const;
	BigInt sum(const BigInt& l, const BigInt& r) const;
	BigInt pro(const BigInt& l, const BigInt& r) const;
};

// constructors

BigInt::BigInt()
{
	I.push_back(0);
}

BigInt::BigInt(string s)
{
	//
}

BigInt::BigInt(int i)
{
	int k = std::abs(i);
	I.push_back(k);
	positive = (i >= 0);
}

// arithmetic operators

BigInt BigInt::operator+(const BigInt &other) const
{
	BigInt result(sum(*this,other));
	return result;
}

BigInt BigInt::operator*(const BigInt &other) const
{
	BigInt result(pro(*this,other));
	return result;
}

// comparison operators

bool BigInt::operator==(const BigInt &other) const
{
	if (bothZero(*this,other)) return true;
	if ((*this).positive != other.positive) return false;
	
	return absComp(*this,other) == 0;
}

bool BigInt::operator!=(const BigInt &other) const
{
	return !(*this == other);
}

bool BigInt::operator<(const BigInt &other) const
{
	if (bothZero(*this,other)) return false;
	else if (((*this).positive && !other.positive)) return false; 
	else if ((!(*this).positive && other.positive)) return true;

	return absComp(*this,other) == -1;
}

bool BigInt::operator>(const BigInt &other) const
{
	if (bothZero(*this,other)) return false;
	else if (((*this).positive && !other.positive)) return true;
	else if ((!(*this).positive && other.positive)) return false;
	
	return absComp(*this,other) == 1;
}

bool BigInt::operator<=(const BigInt &other) const
{
	return !(*this > other);
}

bool BigInt::operator>=(const BigInt &other) const
{
	return !(*this < other);
}

// helper functions

bool BigInt::eitherZero(const BigInt& l, const BigInt& r) const
{
	BigInt zero;
	return absComp(l,zero) == 0 || absComp(r,zero) == 0;
}

bool BigInt::bothZero(const BigInt& r, const BigInt& r) const
{
	BigInt zero;
	return absComp(l,zero) == 0 && absComp(r,zero) == 0;
}

// returns comparison of |l| and |r|
int BigInt::absComp(const BigInt& l, const BigInt& r) const
{
	if (l.I.size() > r.I.size()) return 1;
	else if (l.I.size() < r.I.size()) return -1;
	else {
		for (int i = l.I.size()-1; i >= 0; --i) {
			if (l.I[i] > r.I[i]) return 1;
			else if (l.I[i] < r.I[i]) return -1;
		}
		return 0;
	}
}

// returns |l|+|r|; precond: |l|>|r|
BigInt BigInt::sum(const BigInt& l, const BigInt& r) const
{
	if (l.I.size() < r.I.size()) std::cerr << "BigInt:sum error" << endl;
	BigInt result(l);
	for (int i = 0; i < l.I.size()-1; ++i) {
		result[i] += r[i];
		if (result[i] > 1000000) {
			++result[i+1];
			result[i] -= 1000000;
		}
	}
	if (result[l.I.size()-1] > 1000000) {
		result.push_back(1);
		result[l.I.size()-1] -= 1000000;
	}
}

// returns |l|*|r|; precond: |l|>|r|
BigInt BigInt::pro(const BigInt& l, const BigInt& r) const
{
	if (l.I.size() < r.I.size()) std::cerr << "BigInt:pro error" << endl;
	BigInt result;
	if (eitherZero(l,r));
	else {
		for (int i = 0; i < r.I.size(); ++i) {
			if (r.I[i] == 0);
			else {
				BigInt temp;
				for (int j = 0; j < i; ++i) 
					temp.I.push_back(0);
				for (int j = 0; j < l.I.size(); ++i)
					temp.I.push_back(l.I[j]);
				if (r.I[i] == 1);
				else {
					for (int j = 0; j < temp.I.size(); ++j) {
						//
					}
					//
				}
			}
		}
	}
}