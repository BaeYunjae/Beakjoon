#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int num, cost;

	bool operator<(Node right) const {
		return cost > right.cost;
	}
};

int n, v, e;
int a, b;
int mems[101];
int dist[2][1001]; // 0: KIST, 1: 씨알푸드
vector<Node> vect[1001];

void dijkstra(int num, int place) {
	priority_queue<Node> pq;

	for (int i = 1; i <= v; i++) dist[place][i] = 1e9;
	dist[place][num] = 0;

	pq.push({ num, 0 });

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		for (int i = 0; i < vect[now.num].size(); i++) {
			Node next = vect[now.num][i];

			int nextCost = now.cost + next.cost;
			if (dist[place][next.num] <= nextCost) continue;

			dist[place][next.num] = nextCost;
			pq.push({ next.num, nextCost });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> v >> e >> a >> b;

	for (int i = 0; i < n; i++) {
		cin >> mems[i];
	}

	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		vect[from].push_back({ to, cost });
		vect[to].push_back({ from, cost });
	}

	// 목적지에서 가는 것과 출발지에서 가는 것은 동일
	dijkstra(a, 0);
	dijkstra(b, 1);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if (dist[j][mems[i]] == 1e9) {
				ans = -1;
				cout << ans;
				return 0;
			}
			else {
				ans += dist[j][mems[i]];
			}
		}
	}

	cout << ans;
}