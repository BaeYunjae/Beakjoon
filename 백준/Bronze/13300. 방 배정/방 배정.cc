#include <iostream>
using namespace std;

int students[2][7];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	int s, y;
	for (int i = 0; i < n; i++) {
		cin >> s >> y;
		students[s][y]++;
	}

	int cnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= 6; j++) {
			if (students[i][j] == 0) continue;
			if (students[i][j] > k) {
				int nowCnt = students[i][j] / k;
				if (students[i][j] % k == 0) {
					cnt += nowCnt;
				}
				else {
					cnt += nowCnt + 1;
				}
			}
			else {
				cnt++;
			}
		}
	}

	cout << cnt;
}