#include <iostream>
#include <string>
using namespace std;

int a1[26];
int a2[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	string s1, s2;
	while (n--) {
		cin >> s1 >> s2;

		for (auto ch : s1) a1[ch - 'a']++;
		for (auto ch : s2) a2[ch - 'a']++;

		bool flag = true;
		for (int i = 0; i < 26; i++) {
			if (a1[i] != a2[i]) {
				flag = false;
				break;
			}
		}
		if (flag) cout << "Possible\n";
		else cout << "Impossible\n";

		fill(a1, a1 + 26, 0);
		fill(a2, a2 + 26, 0);
	}
}