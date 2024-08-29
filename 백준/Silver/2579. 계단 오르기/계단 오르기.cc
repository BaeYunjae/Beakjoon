// 1. 테이블 정의하기
// 2. 점화식 구하기
// 3. 초기값 정하기

/*
1 -> 2 / 3
2 <- 1 / 0
3 <- (1x) 2 / 1 <- 0 / 0
4 <- (2x) 3 / 2 <- 1 / 1
5 <- (3x) 4 / 3 <- 2 / 2

*/

#include <iostream>
#include <algorithm>
using namespace std;

int stairs[301];
int dp[301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> stairs[i];
	}

	dp[1] = stairs[1];
	dp[2] = dp[1] + stairs[2];
	dp[3] = max(stairs[2] + stairs[3], dp[1] + stairs[3]);

	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 3] + stairs[i - 1], dp[i - 2]) + stairs[i];
	}

	cout << dp[n];
}

