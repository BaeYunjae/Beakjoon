#include <iostream>
using namespace std;

int n, a, b, m;
int family[101][101];
bool visited[101];

int ans = -1;

void dfs(int now, int chon) {
	visited[now] = true;

	if (now == b) {
		ans = chon;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] || family[now][i] == 0) continue;

		dfs(i, chon + 1);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> a >> b >> m;

	while (m--) {
		int x, y;
		cin >> x >> y;

		family[x][y] = 1;
		family[y][x] = 1;
	}

	dfs(a, 0);

	cout << ans;
}
