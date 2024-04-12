#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int n, k;
int nowTime[100001];

int bfs(int start) {
	queue<int> q;
	q.push(start);
	nowTime[start] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now < 0 || now > 100000) continue;
		if (now == k) return nowTime[now];

		if (now - 1 >= 0 && nowTime[now - 1] == 0) {
			nowTime[now - 1] = nowTime[now] + 1;
			q.push(now- 1);
		}
		if (now + 1 <= 100000 && nowTime[now + 1] == 0) {
			nowTime[now + 1] = nowTime[now] + 1;
			q.push(now + 1);
		}
		if (now * 2 <= 100000 && nowTime[now * 2] == 0) {
			nowTime[now * 2] = nowTime[now] + 1;
			q.push(now * 2);
		}
	}
}

int main() {
	cin >> n >> k;

	cout << bfs(n);
}