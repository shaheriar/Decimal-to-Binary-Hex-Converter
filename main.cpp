#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

string binary(int n) {
	stack<int> s;
	string result = "";
	
	while (n >= 1) {
		s.push(n % 2);
		n /= 2;
	}
	
	int i = s.size();
	int j = 0;
	
	while (!s.empty()) {
		
		if (i % 4 != 0) {
			result += "0";
			i++;
			
		} else {
			result += to_string(s.top());
			s.pop();
		}
		
		j++;
		
		if (j % 4 == 0)
			result+=" ";
		
	}
	
	return result;
}

vector<string> hexvector(stack<int> s) {
	vector<string> v;
	
	while(!s.empty()) {
		switch(s.top()) {
			case 10:
				v.push_back("A"); break;
			case 11:
				v.push_back("B"); break;
			case 12:
				v.push_back("C"); break;
			case 13:
				v.push_back("D"); break;
			case 14:
				v.push_back("E"); break;
			case 15:
				v.push_back("F"); break;
			default:
				v.push_back(to_string(s.top())); break;
		}
		s.pop();
	}
	return v;
}

string hexadecimal(int n) {
	stack<int> s;
	string result = "0x";
	
	while (n >= 1) {
		s.push(n % 16);
		n /= 16;
	}
	
	vector<string> vv = hexvector(s);
	
	if (vv.size() < 2)
		result+="0";
	
	for (auto i : vv) {
		result += i;
	}
	
	return result;
}

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
	
	while (n != -1) {
		cout << endl <<         "Decimal: " << n;
		cout << endl <<         "Binary: " << binary(n);
		cout << endl <<         "Hexadecimal: " << hexadecimal(n);
		
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
	}
	
	return 0;
}