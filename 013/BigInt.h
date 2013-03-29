#include <iostream>
#include <sstream>
#include <list>

using namespace std;

class BigInt {
public:
	// constructors
	BigInt();
	BigInt(string s);
	BigInt(int i);
	// other
	bool positive;
	string str() const;							// to string method
	// arithmetic operators
	BigInt operator+(const BigInt& other) const;
	BigInt operator-(const BigInt& other) const;
	BigInt operator*(const BigInt& other) const;
	BigInt operator/(const BigInt& other) const;
	BigInt operator%(const BigInt& other) const;
	// compound assignment operators
	BigInt& operator+=(const BigInt& other);
	BigInt& operator-=(const BigInt& other);
	BigInt& operator*=(const BigInt& other);
	BigInt& operator/=(const BigInt& other);
	BigInt& operator%=(const BigInt& other);
	// comparison operators
	bool operator==(const BigInt& other) const;
	bool operator!=(const BigInt& other) const;
	bool operator>(const BigInt& other) const;
	bool operator<(const BigInt& other) const;
	bool operator>=(const BigInt& other) const;
	bool operator<=(const BigInt& other) const;
	// typedefs
	typedef list<char>::iterator pos;
	typedef list<char>::const_iterator cpos;
private:
	list<char> I;
	BigInt zero() const;
	int absComp(const BigInt& a, const BigInt& b) const;
	bool eitherZero(const BigInt& a, const BigInt& b) const;
	bool bothZero(const BigInt& a, const BigInt& b) const;
	BigInt sum(const BigInt& a, const BigInt& b) const;
	BigInt diff(const BigInt& a, const BigInt& b) const;
	BigInt prod(const BigInt& a, const BigInt& b) const;
	BigInt div(const BigInt& a, const BigInt& b) const;
	BigInt mod(const BigInt& a, const BigInt& b) const;
};

// constructors

BigInt::BigInt() 
{
	I.push_back('0');
}

BigInt::BigInt(string s) 
{
	istringstream iss(s);
	char ch;
	if (iss.get(ch)) {
		if (ch == '+') positive = true;
		else if (ch == '-') positive = false;
		else iss.unget();
	}
	while (iss) {
		iss >> ch;
		if (iss) {
			if (isdigit(ch)) I.push_front(ch);
			else cerr << "BigInt construction fail";
		}
	}
	if (I.empty()) {
		I.push_back('0');
		positive = true;
	}
	else {	
		pos i = I.end();
		--i;
		while(i != I.begin() && *i == '0') {
			--i;
			I.pop_back();
		}
	}
}

BigInt::BigInt(int i) 
{
	string s = to_string(i);
	istringstream iss(s);
	char ch;
	if (iss.get(ch)) {
		if (ch == '+') positive = true;
		else if (ch == '-') positive = false;
		else iss.unget();
	}
	while (iss) {
		iss >> ch;
		if (iss) {
			if (isdigit(ch)) I.push_front(ch);
			else cerr << "BigInt construction fail";
		}
	}
	if (I.empty()) {
		I.push_back('0');
		positive = true;
	}
}

// IO operators

string BigInt::str() const
{
	ostringstream oss;
	if (!positive) oss << '-';
	cpos iter = I.cend();
	--iter;

	while (iter != I.cbegin()) {
		oss << *iter;
		--iter;
	}
	oss << *iter;
	return oss.str();
}

ostream & operator<<(ostream& out, const BigInt& bi) 
{
	out << bi.str();
	return out;
}

// arithmetic operators

BigInt BigInt::operator+(const BigInt &other) const
{
	BigInt result;
	if ((*this).positive) {
		if (other.positive) {
			if (absComp(*this,other) > 0) result = sum(*this,other);
			else result = sum(other,*this);
			result.positive = true;
		}
		else {
			if (absComp(*this,other) > 0) {
				result = diff(*this,other);
				result.positive = true;
			}
			else if (absComp(*this,other) < 0){
				result = diff(other,*this);
				result.positive = false;
			}
		}
	}
	else {
		if(other.positive) {
			if (absComp(*this,other) > 0) {
				result = diff(*this,other);
				result.positive = false;
			}
			else if (absComp(*this,other) < 0) {
				result = diff(other,*this);
				result.positive = true;
			}
		}
		else {
			if (absComp(*this,other) > 0) result = sum(*this,other);
			else result = sum(other,*this);
			result.positive = false;
		}
	}
	if (result == zero()) result.positive = true;
	return result;
}

BigInt BigInt::operator-(const BigInt &other) const
{
	BigInt result;
	BigInt temp = other;
	temp.positive = !(temp.positive);
	result = *this + temp;
	return result;
}

BigInt BigInt::operator*(const BigInt &other) const
{
	BigInt result;
	if (eitherZero(*this,other)) result == zero();
	else {
		result = prod(*this,other);
		if ((*this).positive == other.positive) result.positive = true;
		else result.positive = false;
	}
	return result;
}

BigInt BigInt::operator/(const BigInt &other) const
{
	BigInt result;
	if (other == zero()) cerr << "BigInt::operator/ error, division by zero!";
	else {
		if (absComp(*this,other) < 0) result == zero();
		else result = div(*this,other);

		if ((*this).positive == other.positive) result.positive = true;
		else result.positive = false;
	}
	return result;
}

BigInt BigInt::operator%(const BigInt &other) const
{
	BigInt result;
	if (other == zero()) cerr << "BigInt::operator% error, division by zero!";
	else {
		if (absComp(*this,other) < 0) result == *this;
		else result = mod(*this,other);

		if ((*this).positive) result.positive = true;
		else result.positive = false;
	}
	return result;
}

// compound assignment operators

BigInt& BigInt::operator+=(const BigInt &other) 
{
	*this = *this + other;
	return *this;
}

BigInt& BigInt::operator-=(const BigInt &other)
{
	*this = *this - other;
	return *this;
}

BigInt& BigInt::operator*=(const BigInt &other)
{
	*this = *this * other;
	return *this;
}

BigInt& BigInt::operator/=(const BigInt &other)
{
	*this = *this - other;
	return *this;
}

BigInt& BigInt::operator%=(const BigInt &other)
{
	*this = *this % other;
	return *this;
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

// returns comparison of |a| and |b|
int BigInt::absComp(const BigInt& a, const BigInt& b) const
{
	if (a.I.size() > b.I.size()) return 1;
	else if (a.I.size() < b.I.size()) return -1;
	else {
		cpos i = a.I.cend();
		cpos j = b.I.cend();
		--i;
		--j;
		while (i != a.I.cbegin()) {
			if (int(*i) > int(*j)) return 1;
			else if (int(*i) < int(*j)) return -1;
			--i;
			--j;
		}
		if (int(*i) > int(*j)) return 1;
		else if (int(*i) < int(*j)) return -1;
		return 0;
	}
}

BigInt BigInt::zero() const
{
	BigInt zero;
	return zero;
}

bool BigInt::eitherZero(const BigInt& a, const BigInt& b) const
{
	return absComp(a,zero()) == 0 || absComp(b,zero()) == 0;
}

bool BigInt::bothZero(const BigInt& a, const BigInt& b) const
{
	return absComp(a,zero()) == 0 && absComp(b,zero()) == 0;
}

// returns |a| + |b|, a must be larger than b
BigInt BigInt::sum(const BigInt& a, const BigInt& b) const
{
	if (a.I.size() < b.I.size()) cerr << "BigInt::sum error, a < b";
	BigInt c(a);
	pos i = c.I.begin();
	cpos j = b.I.cbegin();
	while (j != b.I.cend()) {
		// carrying over operation
		if (int(*i)+int(*j)-2*int('0') >= 10) {
			++i;
			if (i != c.I.end()) {
				*i += 1;
				--i;
			}
			else {
				--i;
				c.I.push_back('1');
			}
			*i = char((int(*i)+int(*j)-2*int('0')-10)+int('0'));
		}
		else *i = char(int(*i)+int(*j)-int('0'));
		++i;
		++j;
	}
	while (i != c.I.end()) {
		if (int(*i)-int('0') >= 10) {
			++i;
			if (i != c.I.end()) {
				*i += 1;
				--i;
			}
			else {
				--i;
				c.I.push_back('1');
			}
			*i = char(int(*i)-10);
		}
		++i;
	}
	return c;
}

// returns |a| - |b|, a must be larger than b
BigInt BigInt::diff(const BigInt& a, const BigInt& b) const
{
	if (a.I.size() < b.I.size()) cerr << "BigInt::diff error, a < b" << endl;
	BigInt c(a);
	pos i = c.I.begin();
	cpos j = b.I.cbegin();
	while(i != c.I.end() && j != b.I.cend()) {
		// carry over operation
		if (int(*i)-int(*j) < 0) {
			++i;
			*i = char(int(*i)-1);
			--i;
			*i = char(10+int('0')+int(*i)-int(*j));
		}
		else *i = char(int('0')+int(*i)-int(*j));
		++i;
		++j;
	}
	i = c.I.end();
	--i;
	while(i != c.I.begin() && *i == '0') {
		--i;
		c.I.pop_back();
	}
	return c;
}

// returns |a| * |b|
BigInt BigInt::prod(const BigInt& a, const BigInt& b) const
{
	BigInt c;
	// if either a or b is zero just return zero
	if (eitherZero(a,b));
	else {
		// place = current digit place of b
		int place = 0;
		// add ones digit of b * a plus tens digit of b * a plus ...
		for (cpos j = b.I.cbegin(); j != b.I.cend(); ++j) {
			BigInt temp;
			if (*j == '0');
			else {
				// multiply by 10 till we get to right place
				temp = a;
				for (int k = 0; k < place; ++k) {
					temp.I.push_front('0');
				}
				if (*j == '1');
				else {
					pos i = temp.I.begin();
					int carry = 0;
					while (i != temp.I.end()) {
						int current = (int(*j)-'0')*(int(*i)-'0')+carry;
						*i = char((current%10)+'0');
						carry = current/10;
						++i;
					}
					while (carry > 0) {
						temp.I.push_back(char(carry%10+'0'));
						carry /= 10;
					}
				}
			}
			c += temp;
			++place;
		}
	}
	return c;
}

// returns |a| / |b|, a must be larger than b
BigInt BigInt::div(const BigInt& a, const BigInt& b) const
{
	if (a.I.size() < b.I.size()) cerr << "BigInt::div error, a < b" << endl;
	BigInt c;
	if (a == zero());
	else if (b == zero()) cerr << "BigInt::div error, division by zero";
	else {
		int k = (a.I.size()-b.I.size());
		BigInt d(a);
		d.positive = true;
		while (k >= 0) {
			BigInt temp(b);
			temp.positive = true;
			for (int j = 0; j < k; ++j) {
				temp.I.push_front('0');
			}
			// determine ith digit
			int c_i = 0;
			while((d-temp) >= zero()) {
				++c_i;
				d -= temp;
			}
			c.I.push_front(char(c_i+'0'));
			--k;
		}
	}
	// eliminate leading zeros
	pos i = c.I.end();
	--i;
	while(i != c.I.begin() && *i == '0') {
		--i;
		c.I.pop_back();
	}
	return c;
}

// returns |a| % |b|
BigInt BigInt::mod(const BigInt& a, const BigInt& b) const
{
	BigInt c(a);
	if (a == zero());
	else if (b == zero()) cerr << "BigInt::mod error, division by zero";
	else if (b.I.size() > a.I.size());
	else {
		int k = (a.I.size()-b.I.size());
		c.positive = true;
		while (k >= 0) {
			BigInt temp(b);
			temp.positive = true;
			for (int j = 0; j < k; ++j) {
				temp.I.push_front('0');
			}
			while((c-temp) >= zero()) {
				c -= temp;
			}
			--k;
		}
	}
	// eliminate leading zeros
	pos i = c.I.end();
	--i;
	while(i != c.I.begin() && *i == '0') {
		--i;
		c.I.pop_back();
	}
	return c;
}