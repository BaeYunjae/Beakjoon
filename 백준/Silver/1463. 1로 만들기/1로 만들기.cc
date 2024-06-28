#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int num, cnt;
};

int n;
int visited[1000001];
int dist[1000001];

void dijkstra(int x) {
	queue<Node> q;
	q.push({ x, 0 });

	for (int i = 0; i <= n; i++) dist[i] = 1e9;
	dist[x] = 0;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (now.num % 3 == 0) {
			int next = now.num / 3;
			if (dist[next] > now.cnt + 1) {
				dist[next] = now.cnt + 1;
				q.push({ next, now.cnt + 1 });
			}
		}

		if (now.num % 2 == 0) {
			int next = now.num / 2;
			if (dist[next] > now.cnt + 1) {
				dist[next] = now.cnt + 1;
				q.push({ next, now.cnt + 1 });
			}
		}

		if (dist[now.num - 1] > now.cnt + 1) {
			dist[now.num - 1] = now.cnt + 1;
			q.push({ now.num - 1, now.cnt + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	dijkstra(n);

	cout << dist[1];
}