#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s[3];
	for (int i = 0; i < 3; i++) cin >> s[i];

	int next = 0;
	for (int i = 0; i < 3; i++) {
		// 1. Fizzbuzz 찾기 = 15의 배수
		if (s[i] == "FizzBuzz") {
			if (i == 0 || i == 2) {
				next = stoi(s[1]) + 2;
			}
			else if (i == 1) {
				next = stoi(s[2]) + 1;
			}
		}
		// 2. Fizz가 있을 때 
		else if (s[i] == "Fizz") {
			if (i == 0) {
				if (s[1] == "Buzz") {
					next = stoi(s[2]) + 1;
				}
				else {
					next = stoi(s[1]) + 2;
				}
			}
			else if (i == 1) {
				if (s[2] != "Buzz") {
					next = stoi(s[2]) + 1;
				}
				else {
					next = stoi(s[0]) + 3;
				}
			}
			else if (i == 2) {
				if (s[1] != "Buzz") {
					next = stoi(s[1]) + 2;
				}
				else {
					next = stoi(s[0]) + 3;
				}
			}
		}
		// 3. Buzz가 있을 때 
		else if (s[i] == "Buzz") {
			if (i == 0) {
				if (s[1] == "Fizz") {
					next = stoi(s[2]) + 1;
				}
				else {
					next = stoi(s[1]) + 2;
				}
			}
			else if (i == 1) {
				if (s[2] != "Fizz") {
					next = stoi(s[2]) + 1;
				}
				else {
					next = stoi(s[0]) + 3;
				}
			}
			else if (i == 2) {
				if (s[1] != "Fizz") {
					next = stoi(s[1]) + 2;
				}
				else {
					next = stoi(s[0]) + 3;
				}
			}
		}
	}

	if (next % 15 == 0) cout << "FizzBuzz";
	else if (next % 3 == 0 && next % 5 != 0) cout << "Fizz";
	else if (next % 3 != 0 && next % 5 == 0) cout << "Buzz";
	else cout << next;
}