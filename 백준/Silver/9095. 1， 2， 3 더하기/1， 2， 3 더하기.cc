#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	int d[11] = { 0 };

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	for (int i = 4; i < 11; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	while (T--) {
		int n;
		cin >> n;

		cout << d[n] << "\n";
	}
}