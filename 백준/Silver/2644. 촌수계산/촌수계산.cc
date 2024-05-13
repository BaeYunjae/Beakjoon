/* 
\ 1 2 3 4 5 6 7 8 9
1 0 1 1 0 0 0 0 0 0
2 1 0 0 0 0 0 1 1 1
3 1 0 0 0 0 0 0 0 0
4 0 0 0 0 1 1 0 0 0
5 0 0 0 1 0 0 0 0 0
6 0 0 0 1 0 0 0 0 0
7 0 1 0 0 0 0 0 0 0 
8 0 1 0 0 0 0 0 0 0 
9 0 1 0 0 0 0 0 0 0 
*/

#include <iostream>
using namespace std;

int n, a, b, m;
int family[101][101];
int parent[101];
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

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	while (m--) {
		int x, y;
		cin >> x >> y;

		family[x][y] = 1;
		family[y][x] = 1;
	}

	dfs(a, 0);

	cout << ans;
}
