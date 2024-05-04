#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
int path[9];
bool used[9];

void dfs(int level, int now) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	int tmp = 0;
	for (int i = now; i < n; i++) {
		if (used[i] || tmp == arr[i]) continue;

		path[level] = arr[i];
		used[i] = true;
		tmp = arr[i];
		dfs(level + 1, i);
		used[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	dfs(0, 0);
}