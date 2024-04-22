#include <iostream>
using namespace std;

int k;
int arr[14];
int path[6];

void dfs(int level, int now) {
	if (level == 6) {
		for (int i = 0; i < 6; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = now; i < k; i++) {
		path[level] = arr[i];
		dfs(level + 1, i + 1);
		path[level] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> k;
		if (k == 0) return 0;

		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}

		dfs(0, 0);
		cout << "\n";
	}
}