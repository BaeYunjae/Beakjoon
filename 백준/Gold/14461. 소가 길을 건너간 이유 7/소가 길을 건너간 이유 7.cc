#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x, cnt, nowTime;

	bool operator<(Node right) const {
		return nowTime > right.nowTime;
	}
};

int n, t;
int map[101][101];

// 0 : 건넌 횟수 0회, 1 : 1회, 2 : 2회 => 3회일 때 0으로 초기화
int visited[3][101][101];

int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

void input() {
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

void dijkstra() {
	priority_queue<Node> pq;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				visited[i][j][k] = 21e8;
			}
		}
	}

	visited[0][0][0] = 0;
	pq.push({ 0, 0, 0, 0 });

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

			int nextCnt = now.cnt + 1;
			int nextTime = now.nowTime + t;
			if (nextCnt == 3) {
				nextCnt = 0;
				nextTime += map[ny][nx];
			}

			if (visited[nextCnt][ny][nx] <= nextTime) continue;
			visited[nextCnt][ny][nx] = nextTime;
			pq.push({ ny, nx, nextCnt, nextTime });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	dijkstra();

	int ans = 21e8;
	for (int i = 0; i < 3; i++) {
		if (ans > visited[i][n - 1][n - 1]) {
			ans = visited[i][n - 1][n - 1];
		}
	}

	cout << ans;
}