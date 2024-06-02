#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, cnt = -1, sum = 0;
	while (1) {
		cin >> n;
		if (n == -1) return 0;

		int* arr = new int[n]; // 동적 할당
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {  // 약수는 현재 값과 나누어 떨어지는 수 
				arr[++cnt] = i;
				sum += i;
			}
		}

		// 완전수라면
		if (sum == n) {
			cout << n << " = ";
			for (int x = 0; x <= cnt; x++) {
				cout << arr[x];
				if (x != cnt) {
					cout << " + ";
				}
			}
			cout << "\n";
		}
		else {
			cout << n << " is NOT perfect.\n";
		}

		delete[] arr;
		cnt = -1, sum = 0;
	}
}