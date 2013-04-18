/*
	Bruce Zheng
	BigInt v2
	
	New version of BigInt, which basically stores BigInts as a base one million number. WIP!

	4/15/2013: Implemented constructors, comparison operators. Only handles unsigned BigInts at the
	moment!
	4/18/2013: Finished unsigned addition/multiplication, input/output
*/

#include <iostream>
#include <string>
#include <vector>

int length(int n)
{
	if (n >= 1000) {
		if (n >= 100000) return 6;
		else {
			if (n >= 10000) return 5;
			else return 4;
		}
	}
	else {
		if (n >= 100) return 3;
		else {
			if (n >= 10) return 2;
			else return 1;
		}
	}
}

const int BI_base = 1000000;

class BigInt {
public:
	// constructors
	BigInt();
	BigInt(std::string s);
	BigInt(int i);
	// other
	bool positive;
	std::string str() const;
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
	std::vector<int> I;
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
	positive = true;
}

BigInt::BigInt(std::string s)
{
	int l = s.length();
	int i = 6;
	while (i < l) {
		I.push_back(atoi(s.substr(l-i,6).c_str()));
		i += 6;
	}
	i -= 6;
	I.push_back(atoi(s.substr(0,l-i).c_str()));
	positive = true;
}

BigInt::BigInt(int i)
{
	int k = std::abs(i);
	if (k >= BI_base) {
		I.push_back(k%BI_base);
		I.push_back(k/BI_base);
	}
	else I.push_back(k);
	positive = (i >= 0);
}

// other

std::string BigInt::str() const
{
	std::string result;
	result += std::to_string(I[I.size()-1]);
	for (int i = I.size()-2; i >= 0; --i) {
		for (int j = length(I[i]); j < 6; ++j)
			result += '0';
		result += std::to_string(I[i]);
	}
	return result;
}

std::ostream& operator<<(std::ostream& out, const BigInt& big)
{
	out << big.str();
	return out;
}

// arithmetic operators

BigInt BigInt::operator+(const BigInt &other) const
{
	if (*this > other) return sum(*this,other);
	else return sum(other,*this);
}

BigInt BigInt::operator*(const BigInt &other) const
{
	if (*this > other) return pro(*this,other);
	else return pro(other,*this);
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

bool BigInt::bothZero(const BigInt& l, const BigInt& r) const
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
	if (l.I.size() < r.I.size()) std::cerr << "BigInt:sum error" << std::endl;
	BigInt result(l);
	for (int i = 0; i < r.I.size()-1; ++i) {
		result.I[i] += r.I[i];
		if (result.I[i] >= BI_base) {
			++result.I[i+1];
			result.I[i] -= BI_base;
		}
	}
	result.I[r.I.size()-1] += r.I[r.I.size()-1];
	// if carryover operation at last place, push_back more digits
	if (result.I[r.I.size()-1] >= BI_base) {
		if (l.I.size() == r.I.size()) result.I.push_back(1);
		else ++result.I[r.I.size()];
		result.I[r.I.size()-1] -= BI_base;
	}
	return result;
}

// returns |l|*|r|; precond: |l|>|r|
BigInt BigInt::pro(const BigInt& l, const BigInt& r) const
{
	if (l.I.size() < r.I.size()) std::cerr << "BigInt:pro error" << std::endl;
	BigInt result;
	if (eitherZero(l,r));
	else {
		for (int i = 0; i < r.I.size(); ++i) {
			if (r.I[i] == 0);
			else {
				BigInt temp;
				temp.I.clear();
				for (int j = 0; j < i; ++j) 
					temp.I.push_back(0);
				int overflow = 0;
				for (int j = 0; j < l.I.size(); ++j) {
					long long mult = long long(l.I[j])*long long(r.I[i]);
					int nextover = (mult+overflow)/BI_base;
					temp.I.push_back(int((mult+overflow)%BI_base));
					overflow = nextover;
				}
				if (overflow > 0) temp.I.push_back(overflow);
				result = result + temp;
			}
		}
	}
	return result;
}