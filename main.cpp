#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;
vector<string> hex(stack<int>);

int main() {
	string input;
	int n;
	cout << "Enter number: ";
	cin >> input;
	try {
		n = stoi(input);
	} catch(const invalid_argument& error) {
		cout << endl << "Invalid input. Exiting." << endl;
		return 1;
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
		cout << endl << "Binary: 0b";
		while (!s.empty()) {
			cout << s.top();
			s.pop();
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
		try {
			n = stoi(input);
		} catch(const invalid_argument& error) {
			cout << endl << "Invalid input. Exiting." << endl;
			return 1;
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