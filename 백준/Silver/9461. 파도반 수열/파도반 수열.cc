// 1 1 1 2 2 3 4 5 7
// 1 1 1 (1+1) (1+1) (1+2) (2+2) (2+3) (3+4)
// 0 1 2 3 4 5 6 7 8(5+6)
// DP

#include <iostream>
using namespace std;

int T, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		long long dp[102] = { 0 };
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 1;

		cin >> N;

		for (int i = 3; i < N; i++) {
			dp[i] = dp[i - 3] + dp[i - 2];
		}

		cout << dp[N - 1] << "\n";
	}
}