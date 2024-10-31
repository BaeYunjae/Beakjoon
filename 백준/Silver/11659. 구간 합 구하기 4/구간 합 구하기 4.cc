#include <iostream>
using namespace std;

int n, m;
int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 1. 테이블 정하기
	// 2. 점화식 구하기
	// 3. 초기값 설정하기
	
	cin >> n >> m;
	
	// 첫번째 수
	cin >> dp[1];

	// 두번째부터는 이전 값과 현재 값의 합
	for (int i = 2; i <= n; i++) {
		int now;
		cin >> now;

		dp[i] = dp[i - 1] + now;
	}


	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;

		cout << dp[e] - dp[s - 1] << "\n";
	}
}