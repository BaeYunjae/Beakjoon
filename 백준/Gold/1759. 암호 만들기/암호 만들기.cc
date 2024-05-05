#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char ch[16];
char path[16];
bool used[16];

void dfs(int level, int moNum, int jaNum, int now) {
	if (level == L) {
		if (moNum >= 1 && jaNum >= 2) {
			cout << path << "\n";
		}
		return;
	}

	for (int i = now; i < C; i++) {
		if (used[i]) continue;

		used[i] = true;
		path[level] = ch[i];
		if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u') {
			dfs(level + 1, moNum + 1, jaNum, i);
		}
		else {
			dfs(level + 1, moNum, jaNum + 1, i);
		}
		used[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> ch[i];

	}

	sort(ch, ch + C);

	dfs(0, 0, 0, 0);
}