#include <iostream>
using namespace std;

int n;
int map[17][17];
int dp[3][17][17];

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
}

bool check(int dir, int y, int x) {
	// 다음 방향이 가로거나 세로일 때 빈칸이면 밀 수 있음
	if (dir == 0 || dir == 1) {
		if (map[y][x] == 0) return true;
	}

	// 다음 방향이 대각선일 때는 3방향을 봐야 함
	// y, x는 다음 대각선 위치의 끝 지점
	// (y - 1, x - 1) == (i, j)  (y - 1, x) == (i, j + 1)
	// (y, x - 1) == (i + 1, j)  (y, x) == (i + 1, j + 1)
	else if (dir == 2) {
		if (map[y][x] == 0 && map[y - 1][x] == 0 && map[y][x - 1] == 0) return true;
	}

	return false;
}

void solve() {
	// 시작은 (1, 1) (1, 2)
	dp[0][1][2] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// 현재 파이프 방향이 가로
			// 가로로 밀 수 있는지 확인
			if (check(0, i, j + 1)) dp[0][i][j + 1] += dp[0][i][j];
			// 대각선으로 밀 수 있는지 확인
			if (check(2, i + 1, j + 1)) dp[2][i + 1][j + 1] += dp[0][i][j];

			// 세로
			// 세로 확인
			if (check(1, i + 1, j)) dp[1][i + 1][j] += dp[1][i][j];
			// 대각선 확인
			if (check(2, i + 1, j + 1)) dp[2][i + 1][j + 1] += dp[1][i][j];

			// 대각선
			// 가로 확인
			if (check(0, i, j + 1)) dp[0][i][j + 1] += dp[2][i][j];
			// 세로 확인
			if (check(1, i + 1, j)) dp[1][i + 1][j] += dp[2][i][j];
			// 대각선 확인
			if (check(2, i + 1, j + 1)) dp[2][i + 1][j + 1] += dp[2][i][j];		
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
	cout << dp[0][n][n] + dp[1][n][n] + dp[2][n][n];
}