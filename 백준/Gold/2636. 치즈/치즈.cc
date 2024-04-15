#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[101][101];
int airMap[101][101] = {0,};

int cheese = 0;
queue<pair<int, int>> meltList;

int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) cheese++;
		}
	}
}

void air(int sy, int sx) {
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	airMap[sy][sx] = 1;

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + dir[i][0];
			int nextX = nowX + dir[i][1];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;
			if (map[nextY][nextX] == 1 || airMap[nextY][nextX] == 1) continue;

			airMap[nextY][nextX] = 1;
			q.push({ nextY, nextX });
		}
	}
}

void checkMelt() {
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 1; j++) {
			if (map[i][j] == 0) continue;

			for (int d = 0; d < 4; d++) {
				int ny = i + dir[d][0];
				int nx = j + dir[d][1];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (map[ny][nx] == 1) continue;
				if (airMap[ny][nx] == 1) {
					meltList.push({ i, j });
					break;
				}
			}
		}
	}
}

int solve() {
	int nowTime = 0;
	while (cheese) {
		++nowTime;

		checkMelt();

		if (cheese - meltList.size() == 0) break;
		cheese -= meltList.size();

		while (!meltList.empty()) {
			int nowY = meltList.front().first;
			int nowX = meltList.front().second;

			map[nowY][nowX] = 0;
			meltList.pop();

			air(nowY, nowX);
		}
	}

	return nowTime;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	// 초기 공기 확인 -> 가장자리는 놓일 수 없으니까 0, 0 부터 탐색
	air(0, 0);

	cout << solve() << "\n" << cheese;
}