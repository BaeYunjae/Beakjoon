#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int dist[1000001];


int bfs(int start) {

	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int up = now + U;
		int down = now - D;

		// 위로
		if (up <= F && dist[up] == -1) {
			dist[up] = dist[now] + 1;
			if (up == G) return dist[up];
			q.push(up);
		}

		// 아래로
		if (down >= 1 && dist[down] == -1) {
			dist[down] = dist[now] + 1;
			if (down == G) return dist[down];
			q.push(down);
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> F >> S >> G >> U >> D;

	if (S == G) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= F; i++) {
		dist[i] = -1;
	}

	int ans = bfs(S);
	if (ans == 0) cout << "use the stairs";
	else cout << ans;

	return 0;
}