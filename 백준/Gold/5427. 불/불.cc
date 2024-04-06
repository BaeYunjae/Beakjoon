#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

struct Node {
	int y, x, sec;
};

int w, h;
string map[1001];
int firePath[1001][1001];
int sangPath[1001][1001];

queue<Node> fires;
queue<Node> q;
int sangY, sangX;
int ans = 0;

int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

void init() {
	memset(firePath, -1, sizeof(firePath));
	memset(sangPath, -1, sizeof(sangPath));

	while (!fires.empty()) fires.pop();
	while (!q.empty()) q.pop();
	
	ans = 0;
}

void input() {
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == '*') {
				fires.push({ i, j, 0 });
				firePath[i][j] = 0;
			}

			else if (map[i][j] == '@') {
				sangY = i;
				sangX = j;
				
			}
		}
	}
}

void fireFlood() {
	while (!fires.empty()) {
		Node now = fires.front();
		fires.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];

			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if (map[ny][nx] == '#' || firePath[ny][nx] != -1) continue;

			firePath[ny][nx] = now.sec + 1;
			fires.push({ ny, nx, firePath[ny][nx] });
		}
	}
}

bool escape(int sy, int sx) {
	q.push({ sy, sx, 0 });
	sangPath[sy][sx] = 0;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();



		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];

			if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
				ans = now.sec + 1;
				return true;
			}
			if (map[ny][nx] == '#' || map[ny][nx] == '*') continue;
			if (firePath[ny][nx] != -1 && firePath[ny][nx] <= now.sec + 1) continue;
			if (sangPath[ny][nx] != -1) continue;

			sangPath[ny][nx] = now.sec + 1;
			q.push({ ny, nx, sangPath[ny][nx] });
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	
	while (T--) {
		init();
		input();

		if (!fires.empty()) fireFlood();

		if (!escape(sangY, sangX)) {
			cout << "IMPOSSIBLE" << "\n";
		}
		else {
			cout << ans << "\n";
		}
	}
}