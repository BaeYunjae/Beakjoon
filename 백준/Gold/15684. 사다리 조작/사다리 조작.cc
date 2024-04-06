#include <iostream>
#include <vector>
using namespace std;

int n, m, h;
int map[31][11];

int flag = false;

void input() {
	cin >> n >> m >> h;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[a][b + 1] = 2;
	}
}

bool check() {
	// 모든 세로선 체크
	for (int i = 1; i <= n; i++) {
		int nowNum = i;
		// 모든 가로선 체크
		for (int row = 1; row <= h; row++){
			// 오른쪽으로 이동
			if (map[row][nowNum] == 1) nowNum++;
			// 왼쪽으로 이동
			else if (map[row][nowNum] == 2) nowNum--;
		}

		if (nowNum != i) return false;
	}
	return true;
}

void dfs(int sy, int sx, int add, int newLine, int startNum) {
	if (add == newLine) {
		if (check()) {
			flag = true;
		}
		return;
	}

	for (int row = startNum; row <= h; row++) {
		for (int col = 1; col < n; col++) {
			if (map[row][col] == 0 && map[row][col + 1] == 0) {
				map[row][col] = 1;
				map[row][col + 1] = 2;

				dfs(row, col, add + 1, newLine, row);

				map[row][col] = 0;
				map[row][col + 1] = 0;
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	// 처음에 i번이 i로 가는지 확인
	if (m == 0 || check()) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= 3; i++) {
		dfs(1, 1, 0, i, 1);

		if (flag) {
			cout << i;
			return 0;
		}
	}

	cout << -1;
}