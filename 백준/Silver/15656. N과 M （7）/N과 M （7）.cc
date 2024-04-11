#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int path[8];

void dfs(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		path[level] = arr[i];
		dfs(level + 1);
		path[level] = 0;
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

	dfs(0);
}