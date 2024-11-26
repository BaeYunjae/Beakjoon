#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x;
};

int T, N;
int dy[8] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int dx[8] = { -1, 1, 2, 2, 1, -1, -2, -2 };
int board[301][301];

int dijkstra(int sy, int sx, int ey, int ex) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = -1;
		}
	}

	queue<Node> q;
	q.push({ sy, sx });
	board[sy][sx] = 0;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (ny == ey && nx == ex) {
				return board[now.y][now.x] + 1;
			}
			if (board[ny][nx] != -1) continue;

			q.push({ ny, nx});
			board[ny][nx] = board[now.y][now.x] + 1;
		}
	}

	return board[ey][ex];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		cin >> N;

		int startY, startX, destY, destX;
		cin >> startY >> startX >> destY >> destX;

		if (startY == destY && startX == destX) {
			cout << 0 << "\n";
			continue;
		}

		cout << dijkstra(startY, startX, destY, destX) << "\n";
	}
}