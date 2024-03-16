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
vector<Node> vect[1001];

int ans = 0;

int dijkstra(int num) {
	priority_queue<Node> pq;

	int dist[1001];
	for (int i = 1; i <= v; i++) dist[i] = 1e9;
	dist[num] = 0;

	pq.push({ num, 0 });

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		for (int i = 0; i < vect[now.num].size(); i++) {
			Node next = vect[now.num][i];

			int nextCost = now.cost + next.cost;
			if (dist[next.num] <= nextCost) continue;

			dist[next.num] = nextCost;
			pq.push({ next.num, nextCost });
		}
	}
	
	int toKIST = dist[a];
	int toFood = dist[b];

	if (toKIST == 1e9 || toFood == 1e9) ans = -1;
	else ans += toKIST + toFood;

	return ans;
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

	for (int i = 0; i < n; i++) {
		dijkstra(mems[i]);
	}

	cout << ans;
}