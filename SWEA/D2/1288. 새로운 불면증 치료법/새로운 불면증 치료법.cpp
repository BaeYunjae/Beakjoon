#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	int target = (1 << 10) - 1;

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;

		int visited = 0;
		int count = 0;
		for (count = 1;; count++) {
			string now = to_string(n * count);
			for (char c : now) {
				int num = c - '0';
				visited |= (1 << num);
			}

			if (visited == target) break;
		}

		cout << "#" << tc << " " << n * count << "\n";
	}
}