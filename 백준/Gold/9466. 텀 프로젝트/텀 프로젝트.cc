#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int arr[100001];
bool visited[100001];
bool done[100001];

int teamSize;

void dfs(int now) {
	// 현재 노드 방문 처리
	visited[now] = true;
	int next = arr[now];

	if (!visited[next]) {
		// 아직 방문하지 않은 노드면 DFS 진행
		dfs(next);
	}
	else if (!done[next]) {
		int cur = next;
		while (1) {
			teamSize++;
			if (cur == now) break; // 사이클 끝날 때까지 순회
			cur = arr[cur];
		}
	}

	// 탐색 완료 
	done[now] = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	
	while (T--) {
		int N;
		cin >> N;

		memset(done, false, sizeof(done));
		memset(visited, false, sizeof(visited));

		int teamCnt = 0;

		// 입력 
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}

		for (int i = 1; i <= N; i++) {
			if (visited[i]) continue;

			teamSize = 0;
			dfs(i);
			teamCnt += teamSize;
		}

		cout << N - teamCnt << "\n";
	}
}