#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int dp[300][2];  // [][0] : 연속되지 않은 경우, [][1] : 연속된 경우
	int stairs[300];

	for (int i = 0; i < n; i++) {
		cin >> stairs[i];
	}

	dp[0][0] = stairs[0];
	dp[0][1] = 0;
	dp[1][0] = stairs[1];
	dp[1][1] = stairs[0] + stairs[1];

	for (int i = 2; i < n; i++) {
		// 연속되지 않은 경우, 전전단계에서 온 경우
		dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + stairs[i];
		// 연속된 경우, 무조건 연속되지 않은 경우에서 와야 함
		dp[i][1] = dp[i - 1][0] + stairs[i];
	}

	cout << max(dp[n - 1][0], dp[n - 1][1]);
}