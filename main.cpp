#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

//RETURNS A BINARY OF AN INT
string binary(int n) {
	stack<int> s;
	string result = "";
	
	//BINARY IS BASE 2
	while (n >= 1) {
		s.push(n % 2);
		n /= 2;
	}
	
	int i = s.size();
	int j = 0;
	
	while (!s.empty()) {
		
		//FOR PRECEDING ZEROS
		if (i % 4 != 0) {
			result += "0";
			i++;	
		} else {
			result += to_string(s.top());
			s.pop();
		}
		
		j++;
		
		//A GAP AFTER EVERY NIBBLE
		if (j % 4 == 0)
			result+=" ";
	}
	return result;
}

//RETURNS A HEXADECIMAL OF AN INT
string hexadecimal(int n) {
	stack<int> s;
	string result = "";
	
	//HEXADECIMAL IS BASE 16
	while (n >= 1) {
		s.push(n % 16);
		n /= 16;
	}
	
	while(!s.empty()) {
		switch(s.top()) {
			case 10:
				result += "A"; break;
			case 11:
				result += "B"; break;
			case 12:
				result += "C"; break;
			case 13:
				result += "D"; break;
			case 14:
				result += "E"; break;
			case 15:
				result += "F"; break;
			default:
				result += to_string(s.top()); break;
		}
		s.pop();
	}
	
	//FOR VALUES <= 0x0F
	(result.length() < 2) ? result = "0x0" + result : result = "0x" + result;
	
	return result;
}

//HELPER FUNCTION FOR INPUT VALIDATION
int check(string input) {
	bool done = false;
	int n;
	while (!done) {
		try {
			n = stoi(input); done = true;
		} catch(const invalid_argument& error) {
			cout << endl << "Invalid input. Try again: ";
			cin >> input;
		}
	}
	return n;
}

int main() {
	string input;
	
	cout << "Enter a positive number: ";
	cin >> input;
	int n = check(input);
	
	while (n != -1) {
		cout << endl << "Decimal: " << n;
		
		cout << endl << "Binary: " << binary(n);
		cout << endl << "Hexadecimal: " << hexadecimal(n);
		
		cout << endl << endl << "Enter another number? Enter -1 to quit: ";
		cin >> input;
		n = check(input);
	}
	return 0;
}