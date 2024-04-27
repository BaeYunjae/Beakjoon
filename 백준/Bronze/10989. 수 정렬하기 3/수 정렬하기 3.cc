#include <iostream>
using namespace std;

int DAT[10001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int num;
	while (n--) {
		cin >> num;
		DAT[num]++;
	}

	for (int i = 1; i < 10001; i++) {
		if (DAT[i] == 0) continue;
		while (DAT[i]--) cout << i << "\n";
	}
}