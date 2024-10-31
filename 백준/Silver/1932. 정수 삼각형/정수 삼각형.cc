#include <iostream>
using namespace std;

int n;
int dp[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> dp[i][j];
		}
	}

	// 마지막에서 바로 윗줄부터 dp에 저장
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + dp[i][j];
		}
	}

	cout << dp[0][0];
}