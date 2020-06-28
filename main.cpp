#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;
vector<string> hex(stack<int>);

int main() {
	string input;
	int n;
	cout << "Enter a positive number: ";
	cin >> input;
	bool done = false;
	while (!done) {
		try {
			n = stoi(input); done = true;
		} catch(const invalid_argument& error) {
			cout << endl << "Invalid input. Try again: ";
			cin >> input;
		}
	}
	int nn = n;
	while (n != -1) {
		stack<int> ss;
		stack<int> s;
		cout << endl << "Decimal: " << n;
		while (n >= 1) {
			s.push(n % 2);
			n /= 2;
		}
		while (nn >= 1) {
			ss.push(nn % 16);
			nn /= 16;
		}
		cout << endl << "Binary: ";
		int i = s.size();
		int j = 0;
		while (!s.empty()) {
			if (i % 4 != 0) {
				cout << 0;
				i++;
			} else {
				cout << s.top();
				s.pop();
			}
			j++;
			if (j % 4 == 0) {
				cout << ' ';
			}
		}
		cout << endl << "Hexadecimal: 0x";
		vector<string> vv = hex(ss);
		if (vv.size() < 2) {
			cout << 0;
		}
		for (int i = 0; i < vv.size(); i++) {
			cout << vv.at(i);
		}
		cout << endl << endl << "Enter another number? Enter -1 to quit: ";
		cin >> input;
		done = false;
		while (!done) {
			try {
				n = stoi(input); done = true;
			} catch(const invalid_argument& error) {
				cout << endl << "Invalid input. Try again: ";
				cin >> input;
			}
		}
		nn = n;
	}
	return 0;
}

vector<string> hex(stack<int> ss) {
	vector<string> vec;
	while(!ss.empty()) {
		switch(ss.top()) {
			case 10:
				vec.push_back("A"); break;
			case 11:
				vec.push_back("B"); break;
			case 12:
				vec.push_back("C"); break;
			case 13:
				vec.push_back("D"); break;
			case 14:
				vec.push_back("E"); break;
			case 15:
				vec.push_back("F"); break;
			default:
				vec.push_back(to_string(ss.top())); break;
		}
		ss.pop();
	}
	return vec;
}