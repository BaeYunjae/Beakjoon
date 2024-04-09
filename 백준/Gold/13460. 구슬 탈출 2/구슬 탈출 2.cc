#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct GuSeol {
	int ry, rx, by, bx, cnt;
};

int n, m;
string map[10];
GuSeol start;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visited[11][11][11][11];

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'R') {
				start.ry = i;
				start.rx = j;
			}
			else if (map[i][j] == 'B'){
				start.by = i;
				start.bx = j;
			}
		}
	}

	start.cnt = 0;
}

int bfs() {
	int ret = -1;

	queue<GuSeol> q;
	q.push({start});

	visited[start.ry][start.rx][start.by][start.bx] = 1;

	while (!q.empty()) {
		GuSeol now = q.front();
		q.pop();
	
		if (now.cnt > 10) break;
		if (map[now.ry][now.rx] == 'O' && map[now.by][now.bx] != 'O') {
			ret = now.cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nextRY = now.ry;
			int nextRX = now.rx;
			int nextBY = now.by;
			int nextBX = now.bx;

			// 빨간공 굴리기
			while (1) {
				if (map[nextRY][nextRX] != '#' && map[nextRY][nextRX] != 'O') {
					nextRY += dy[i];
					nextRX += dx[i];
				}
				else {
					// 다음 칸이 벽이라면 이전 위치로 돌아가야 한다
					if (map[nextRY][nextRX] == '#') {
						nextRY -= dy[i];
						nextRX -= dx[i];
					}
					break;
				}
			}

			// 파란공 굴리기
			while (1) {
				if (map[nextBY][nextBX] != '#' && map[nextBY][nextBX] != 'O') {
					nextBY += dy[i];
					nextBX += dx[i];
				}
				else {
					// 다음 칸이 벽이라면 이전 위치로 돌아가야 한다
					if (map[nextBY][nextBX] == '#') {
						nextBY -= dy[i];
						nextBX -= dx[i];
					}
					break;
				}
			}

			// 빨간 공과 파란 공의 도달 위치가 같다면
			if (nextRY == nextBY && nextRX == nextBX) {
				// 구멍에 들어가는 경우는 위에서 처리를 해줬다
				if (map[nextRY][nextRX] != 'O') {
					int redDist = abs(nextRY - now.ry) + abs(nextRX - now.rx);
					int blueDist = abs(nextBY - now.by) + abs(nextBX - now.bx);

					// 거리가 더 먼 구슬이 늦게 도달한 것
					if (redDist > blueDist) {
						nextRY -= dy[i];
						nextRX -= dx[i];
					}
					else {
						nextBY -= dy[i];
						nextBX -= dx[i];
					}
				}
			}

			if (visited[nextRY][nextRX][nextBY][nextBX] == 1) continue;

			visited[nextRY][nextRX][nextBY][nextBX] = 1;
			q.push({ nextRY, nextRX, nextBY, nextBX, now.cnt + 1 });
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	int ret = bfs();
	cout << ret;
}