#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int sum = i;
		int num = i;

		while (num) {
			sum += num % 10;
			num /= 10;
		}

		if (sum == n) {
			cout << i;
			return 0;
		}
	}

	cout << 0;
}