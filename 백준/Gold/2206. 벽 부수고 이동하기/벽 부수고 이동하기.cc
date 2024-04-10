#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x, cnt, crash;
};

int n, m;
char map[1001][1001];

// 0 : 벽을 안 부수고 이동한 거리, 1 : 벽을 부수고 이동한 거리
bool visited[1001][1001][2];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

int bfs() {
	queue<Node> q;
	q.push({ 0, 0, 1, 0 });
	visited[0][0][0] = true;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (now.y == n - 1 && now.x == m - 1) {
			return now.cnt;
		}

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx][now.crash]) continue;

			// 벽을 아직 안 부쉈다면
			if (map[ny][nx] == '0') {
				visited[ny][nx][now.crash] = true;
				q.push({ ny, nx, now.cnt + 1, now.crash });
			}

			// 이미 벽을 부수고 왔다면
			else {
				if (now.crash == 1) continue;
				visited[ny][nx][now.crash] = true;
				q.push({ ny, nx, now.cnt + 1, now.crash + 1 });
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	cout << bfs();
}