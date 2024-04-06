#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
	int y, x, turns, direct;

	bool operator<(Node right) const {
		return turns > right.turns;
	}
};

int w, h;
string map[101];
int startY = -1, startX = -1;
int destY = -1, destX = -1;
int dist[101][101];

int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

void input() {
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		cin >> map[i];
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 'C') {
				if (startY == -1) {
					startY = i;
					startX = j;
				}
				else {
					destY = i;
					destX = j;
				}
			}
		}
	}
}

void dijkstra(int sy, int sx, int direct) {
	priority_queue<Node> pq;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			dist[i][j] = 1e9;
		}
	}

	dist[sy][sx] = 0;
	pq.push({ sy, sx, 0, direct });

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];

			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if (map[ny][nx] == '*') continue;

			int nextTurns = now.turns;
			if (i != now.direct){
				nextTurns = now.turns + 1;
			}

			if (dist[ny][nx] <= nextTurns) continue;

			dist[ny][nx] = nextTurns;
			pq.push({ ny, nx, nextTurns, i });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	int minMirror = 1e9;
	for (int i = 0; i < 4; i++) {
		dijkstra(startY, startX, i);
		minMirror = min(minMirror, dist[destY][destX]);
	}

	cout << minMirror;
}