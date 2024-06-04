#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	int alpha[130] = { 0 };

	for (int i = 0; i < s.length(); i++) {
		alpha[s[i]]++;
	}

	for (int i = 'a'; i <= 'z'; i++) {
		cout << alpha[i] << " ";
	}

	return 0;
}