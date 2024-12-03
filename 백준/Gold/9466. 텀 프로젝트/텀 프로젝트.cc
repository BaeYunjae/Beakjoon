#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[100001];
int chosen[100001];

int bfs(int n) {
	int cnt = 0;
	queue<int> q;

	// 선택받은 학생 넣기
	for (int i = 1; i <= n; i++) {
		if (!chosen[i]) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		cnt++;
		int next = arr[q.front()];
		q.pop();

		chosen[next]--;
		if (!chosen[next]) {
			q.push(next);
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	
	while (T--) {
		int N;
		cin >> N;

		memset(chosen, 0, sizeof(chosen));

		// 입력
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			chosen[arr[i]]++;
		}

		cout << bfs(N) << "\n";
	}
}