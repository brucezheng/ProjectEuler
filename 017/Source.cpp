#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

string to_word(int i) {
	string word;
	string thou = "";
	string hund = "";
	string tens = "";
	string ones = "";
	if (i/1000 > 0) {
		switch (i/1000) {
		case 1: thou = "one"; break;
		case 2: thou = "two"; break;
		case 3: thou = "three"; break;
		case 4: thou = "four"; break;
		case 5: thou = "five"; break;
		case 6: thou = "six"; break;
		case 7: thou = "seven"; break;
		case 8: thou = "eight"; break;
		case 9: thou = "nine"; break;
		}
		thou += " thousand";
	}
	if ((i%1000)/100 > 0) {
		switch ((i%1000)/100) {
		case 1: hund = "one"; break;
		case 2: hund = "two"; break;
		case 3: hund = "three"; break;
		case 4: hund = "four"; break;
		case 5: hund = "five"; break;
		case 6: hund = "six"; break;
		case 7: hund = "seven"; break;
		case 8: hund = "eight"; break;
		case 9: hund = "nine"; break;
		}
		hund += " hundred";
	}
	if((i%100)/10 == 1) {
		switch(i%100) {
		case 10: tens = "ten"; break;
		case 11: tens = "eleven"; break;
		case 12: tens = "twelve"; break;
		case 13: tens = "thirteen"; break;
		case 14: tens = "fourteen"; break;
		case 15: tens = "fifteen"; break;
		case 16: tens = "sixteen"; break;
		case 17: tens = "seventeen"; break;
		case 18: tens = "eighteen"; break;
		case 19: tens = "nineteen"; break;
		}
	}
	else {
		switch ((i%100)/10) {
		case 2: tens = "twenty"; break;
		case 3: tens = "thirty"; break;
		case 4: tens = "forty"; break;
		case 5: tens = "fifty"; break;
		case 6: tens = "sixty"; break;
		case 7: tens = "seventy"; break;
		case 8: tens = "eighty"; break;
		case 9: tens = "ninety"; break;
		default: break;
		}
		switch (i%10) {
		case 1: ones = "one"; break;
		case 2: ones = "two"; break;
		case 3: ones = "three"; break;
		case 4: ones = "four"; break;
		case 5: ones = "five"; break;
		case 6: ones = "six"; break;
		case 7: ones = "seven"; break;
		case 8: ones = "eight"; break;
		case 9: ones = "nine"; break;
		}
	}
	word += thou;
	if (thou != "") {
		if (hund != "" || tens != "" || ones != "") word += " and ";
	}
	word += hund;
	if (hund != "") {
		if (tens != "" || ones != "") word += " and ";
	}
	word += tens;
	if (tens != "") {
		if (ones != "") word += "-";
	}
	word += ones;
	return word;
}

int letter_count(string str) 
{
	istringstream iss(str);
	int count = 0;
	char ch;
	while (iss.get(ch)) {
		if (isalpha(ch)) {
			++count;
		}
	}
	return count;
}

int main() 
{
	int sum = 0;
	for (int i = 1; i <= 1000; i++) {
		sum += letter_count(to_word(i));
	}
	cout << sum << endl;
	char stall;
	cin >> stall;
}