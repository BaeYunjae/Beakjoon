#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int num;
	map<int, int> m;

	while (n--) {
		cin >> num;
		m[num]++;
	}

	for (auto now : m) {
		for (int i = 0; i < now.second; i++) {
			cout << now.first << "\n";
		}
	}
}