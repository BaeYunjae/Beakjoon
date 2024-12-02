// 정육면체, 3차원 -> 동서남북상하, 대각선 이동 불가
// 최대 60초 
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int l, r, c;
	int nowTime;
};

int L, R, C;  // 층, 행, 열
char building[31][31][31];
bool visited[31][31][31];
int startL, startR, startC;
int endL, endR, endC;

int dir[6][3] = { {-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1} };

int bfs(int sl, int sr, int sc) {
	memset(visited, false, sizeof(visited));

	queue<Node> q;
	q.push({ sl, sr, sc, 0});
	visited[sl][sr][sc] = true;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		// 출구 도달
		if (now.l == endL && now.r == endR && now.c == endC) return now.nowTime;

		for (int i = 0; i < 6; i++) {
			int nl = now.l + dir[i][0];
			int nr = now.r + dir[i][1];
			int nc = now.c + dir[i][2];

			if (nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if (building[nl][nr][nc] == '#' || visited[nl][nr][nc]) continue;

			int nextTime = now.nowTime + 1;

			visited[nl][nr][nc] = true;
			q.push({ nl, nr, nc, nextTime });
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 입력
	while (1) {

		cin >> L >> R >> C;

		if (L == 0) break;

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S') {
						startL = i;
						startR = j;
						startC = k;
					}
					else if (building[i][j][k] == 'E') {
						endL = i;
						endR = j;
						endC = k;
					}
				}
			}
		}

		int ans = bfs(startL, startR, startC);
		if (ans == -1) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << ans << " minute(s).\n";
		}
	}
}