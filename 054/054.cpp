/*
	Bruce Zheng
	Problem 054
	5/7/2013

	Wow. This code is terrible. If I ever become famous, don't read this. Goddamn. I spent so much 
	fucking time debugging this crap. Wow. I said wow twice. 'wow'
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

typedef string hand;
typedef pair<bool,vector<int>> sorted_hand;

void pause()
{
	char ch;
	cin >> ch;
}

sorted_hand sort(hand h) 
{
	bool flush = true;
	vector<int> result(5);
	for(int i = 0; i < h.length()/2; ++i) {
		if (isdigit(h[2*i])) result[i] = h[2*i]-48;
		else {
			switch(h[2*i]) {
				case 'T': result[i] = 10; break;
				case 'J': result[i] = 11; break;
				case 'Q': result[i] = 12; break;
				case 'K': result[i] = 13; break;
				case 'A': result[i] = 14; break;
				default: cerr << "Bad hand input (sort)" << endl; break;
			}
		}
		if (2*i-1 > 0 && h[2*i-1] != h[2*i+1])
			flush = false;
	}
	for (int i = 1; i < result.size(); ++i) {
		int k = i;
		while (k != 0 && result[k] < result[k-1]) {
			int temp = result[k-1];
			result[k-1] = result[k];
			result[k] = temp;
			--k;
		}
	}
	return sorted_hand(flush,result);
}

// WOW THIS CODE IS AN ABOMINATION
double eval(hand d) 
{
	double rank = 0;
	sorted_hand s = sort(d);
	vector<int>& num = s.second;
	bool& flush = s.first;
	pair<int,int> dupes(1,1);
	// determine the "n of a kind" numbers of hand
	// dupes.first is "left n of a kind"; dupes.second is "right n of a kind"
	double left_num = 0, right_num = 0;
	for (int i = 0; i < 2; ++i) {
		if (num[i] == num[i+1]) {
			left_num = num[i];
			int temp = 1;
			while(i+1 < 5 && num[i] == num[i+1]) {
				++temp;
				++i;			
			}
			dupes.first = temp;
			break;
		}
	}
	for (int i = 4; i > 2; --i) {
		if (num[i] == num[i-1]) {
			right_num = num[i];
			int temp = 1;
			while(i-1 > -1 && num[i] == num[i-1]) {
				++temp;
				--i;			
			}
			dupes.second = temp;
			break;
		}
	}
	// determine dupe_type and straight_type
	// dupe_type: 0 - no dupes, 1 - one p, 2 - two p, 3 - 3oak, 4 - full house, 5 - 4oak
	// straight_type: 0 - no straight, 1 - normal straight, 2 - facecard straight
	int dupe_type;
	bool straight;
	switch (dupes.first) {
		case 1:
			switch (dupes.second) {
				case 1: dupe_type = 0; break;
				// obscure shit from laziness!! set leftnum to rightnum for later shit
				case 2: dupe_type = 1; left_num = right_num; break;
				case 3: dupe_type = 3; left_num = right_num; break;
				case 4: dupe_type = 5; left_num = right_num; break;
			}
			break;
		case 2:
			switch (dupes.second) {
				case 1: dupe_type = 1; break;
				case 2: dupe_type = 2; break;
				case 3: dupe_type = 4; left_num = right_num; break;
			}
			break;
		case 3:
			switch (dupes.second) {
				case 1: dupe_type = 3; break;
				case 2: dupe_type = 4; break;
				case 3: dupe_type = 3; break;
			}
			break;
		case 4: dupe_type = 5; break;
		default: cerr << "This shit whack yo"; break;
	}
	double straightmod = num[4]/double(100);
	straight = (num[4]-num[0] == 4) && (num[4]-num[1] == 3) && (num[4]-num[2] == 2) && (num[4]-num[3] == 1);
	if (num[4] == 14 && !straight) {
		straight = (num[3]-1 == 4) && (num[3]-num[0] == 3) && (num[3]-num[1] == 2) && (num[3]-num[2] == 1);
		straightmod = .05;
	}
	// ACTUAL EVALUATING GOES HERE
	if (flush) {
		if (straight) {
			if (num[4] == 14 && straightmod == 0.14) rank += 10 + straightmod;
			else rank += 9 + straightmod;
		}
		else if (dupe_type < 4) {
			rank += 6;
			double divider = 100;
			for (int i = 4; i > -1; --i) {
				rank += num[i]/divider;
				divider *= double(100);
			}
		}
		else rank += dupe_type + 3 + left_num/double(100);
	}
	else {
		if (straight) rank += 5 + straightmod;
		else if (dupe_type == 0) {
			rank += 1;
			double divider = 100;
			for (int i = 4; i > -1; --i) {
				rank += num[i]/divider;
				divider *= double(100);
			}
		}
		else if (dupe_type == 1) {
			double divider = 10000;
			rank += 2 + left_num/double(100);
			for (int i = 4; i > -1; --i) {
				if (num[i] != left_num) {
					rank += num[i]/divider;
					//cout << num[i]/divider << endl;
					divider *= double(100);
				}
			}
		}
		else if (dupe_type == 2) {
			rank += 3 + max(left_num,right_num)/double(100)+min(left_num,right_num)/double(10000);
			for (int i = 4; i > -1; --i) {
				if (num[i] != left_num && num[i] != right_num) {
					rank += num[i]/double(1000000);
					break;
				}
			}
		}
		else if (dupe_type == 3) rank += 4 + left_num/double(100);
		else rank += dupe_type + 3 + left_num/double(100);
	}
	//for (int i = 0; i < num.size(); ++i) cout << num[i] << ' ';
	//cout << endl << dupes.first << ' ' << dupes.second << ' ' 
	//	 << dupe_type << ' ' << straight << ' ' << flush << endl;
	return rank;
	// doctor, i think it's saying "..kill me..."!
}

int main()
{
	vector<hand> p1;
	vector<hand> p2;
	ifstream in;
	in.open("poker.txt");
	bool toggle = true;
	hand temp;
	char ch;
	while(in.get(ch)) {
		if (isalnum(ch)) temp += ch;
		if (temp.length() == 10) {
			if (toggle) p1.push_back(temp);
			else p2.push_back(temp);
			temp.clear();
			toggle = !toggle;
		}
	}
	
	int p1_wins = 0;
	int test = 0;
	for (int i = 0; i < p1.size(); ++i) {
		//cout << p1[i] << ' ' << p2[i] << endl;
		//cout << eval(p1[i]) << endl;
		if (eval(p1[i]) - eval(p2[i]) > 0) {
			++p1_wins;
		}
		/*
		else if (int(eval(p1[i])) - int(eval(p2[i])) == 0 && int(eval(p2[i])) > 2) {
			if (test<20) {
				cout << p1[i] << ' ' << p2[i] << endl;
				cout << eval(p1[i]) << ' ' << eval(p2[i]) << endl;
			}
		}
		*/
	}
	cout << p1.size() << ' ' << p2.size() << endl;
	cout << p1_wins << ' ' << test;

	pause();
}