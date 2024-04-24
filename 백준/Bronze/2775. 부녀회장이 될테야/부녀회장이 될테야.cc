#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	int arr[15][15] = { 0 };
	
	// 0층
	for (int i = 1; i < 15; i++) {
		arr[0][i] = i;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			for (int x = 1; x <= j; x++) {
				arr[i][j] += arr[i - 1][x];
			}
		}
	}

	while (T--) {
		int k, n;
		cin >> k >> n;

		cout << arr[k][n] << "\n";
	}
}