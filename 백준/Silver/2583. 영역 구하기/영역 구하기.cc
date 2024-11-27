#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int y, x;
};

int M, N, K;
int graph[101][101];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int bfs(int sy, int sx, int num) {
	int cnt = 0;

	queue<Node> q;
	q.push({ sy, sx });
	graph[sy][sx] = num;
	cnt++;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= M || nx < 0 || nx >= N || graph[ny][nx] != 0) continue;

			graph[ny][nx] = num;
			cnt++;
			q.push({ ny, nx });
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> M >> N >> K;

	while (K--) {
		// 직사각형 왼쪽 아래 & 오른쪽 위
		int lbx, lby, rtx, rty;
		cin >> lbx >> lby >> rtx >> rty;

		// (0, 2) (4, 4) -> (0, 3) (4, 1)  (lbx, lby) (rtx, rty) -> (lbx, M - lby) (rtx, M - rty)
		// (1, 1) (2, 5) -> (1, 4) (2, 0)
		// (4, 0) (6, 2) -> (4, 5) (6, 3) 

		for (int i = M - rty; i < M - lby; i++) {
			for (int j = lbx; j < rtx; j++) {
				graph[i][j] = -1;
			}
		}
	}

	vector<int> ans;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] != 0) continue;
			ans.push_back(bfs(i, j, ans.size() + 1));
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (int i : ans) {
		cout << i << " ";
	}
}