#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a1[26];
int a2[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	for (auto ch : s1) a1[ch - 'a']++;
	for (auto ch : s2) a2[ch - 'a']++;

	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		cnt += abs(a1[i] - a2[i]);
	}

	cout << cnt;
}