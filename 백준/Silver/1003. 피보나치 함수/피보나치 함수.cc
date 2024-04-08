#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	int dp[41] = { 0, 1, 1 };

	for (int i = 3; i < 41; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	while (T--) {
		int n;
		cin >> n;

		if (n == 0) {
			cout << 1 << " " << 0 << "\n";
		}
		else if (n == 1) {
			cout << 0 << " " << 1 << "\n";
		}
		else {
			cout << dp[n - 1] << " " << dp[n] << "\n";
		}
	}
}