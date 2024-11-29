#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node {
	int y, x;
};

int N;
int area[101][101];
bool visited[101][101];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void bfs(int sy, int sx, int height) {

	queue<Node> q;
	q.push({ sy, sx });
	visited[sy][sx] = true;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (area[ny][nx] <= height || visited[ny][nx]) continue;

			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	
	int maxHeight = 0;

	// 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
			cin >> area[i][j];
			maxHeight = max(area[i][j], maxHeight);
		}
	}

	int maxArea = 1;

	for (int h = 1; h < maxHeight; h++) {
		// 방문 초기화
		memset(visited, false, sizeof(visited));

		int cnt = 0;

		// 물에 잠기는 영역 확인
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (area[i][j] > h && !visited[i][j]) {
					cnt++;
					bfs(i, j, h);
				}
			}
		}

		maxArea = max(cnt, maxArea);
	}

	cout << maxArea;
}