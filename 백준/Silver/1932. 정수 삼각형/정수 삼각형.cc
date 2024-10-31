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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n - i; j++) {
			dp[n - i - 1][j] += max(dp[n - i][j], dp[n - i][j + 1]);
		}
	}

	cout << dp[0][0];
}