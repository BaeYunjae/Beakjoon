#include <iostream>
#include <algorithm>
using namespace std;

// 1. 테이블 만들기
int DP[1000001];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	// 2. 점화식 찾기 
	// 3. 초기값 정의하기
	DP[1] = 0;

	for (int i = 2; i <= n; i++) {
		DP[i] = DP[i - 1] + 1;
		if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);
		if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);
	}

	cout << DP[n];

	return 0;
}