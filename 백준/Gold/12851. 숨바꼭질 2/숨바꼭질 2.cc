#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int locate, nowTime;
};

int n, m;
bool visited[100002];
int minTime = 21e8;
int cnt = 0;

void bfs() {
	queue<Node> q;
	q.push({ n, 0 });
	visited[n] = true;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (now.locate == m && !visited[m]) {
			minTime = now.nowTime;
			cnt++;
		}
		else if (now.locate == m && now.nowTime == minTime) {
			cnt++;
		}

		visited[now.locate] = true;

		int nextTime = now.nowTime + 1;
		if (now.locate - 1 >= 0 && !visited[now.locate - 1]) {
			q.push({ now.locate - 1, nextTime });
		}
		if (now.locate + 1 <= 100000 && !visited[now.locate + 1]) {
			q.push({ now.locate + 1, nextTime });
		}
		if (now.locate * 2 <= 100000 && !visited[now.locate * 2]) {
			q.push({ now.locate * 2, nextTime });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	if (n == m) {
		cout << 0 << "\n" << 1;
		return 0;
	}

	bfs();

	cout << minTime << "\n" << cnt;
}