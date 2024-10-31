#include <iostream>
using namespace std;

int n;
int tri[501][501];
long long dp[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	// 가장 마지막 줄은 그대로 메모
	for (int i = 0; i < n; i++) {
		dp[n - 1][i] = tri[n - 1][i];
	}

	// 마지막에서 바로 윗줄부터 dp에 저장
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + tri[i][j];
		}
	}

	cout << dp[0][0];
}